#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= BOOK CLASS =================
class Book {
private:
    int bookId;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        issued = false;
    }

    int getId() {
        return bookId;
    }

    string getTitle() {
        return title;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }

    void displayBook() {
        cout << "Book ID : " << bookId << endl;
        cout << "Title   : " << title << endl;
        cout << "Author  : " << author << endl;
        cout << "Status  : ";

        if (issued)
            cout << "Issued" << endl;
        else
            cout << "Available" << endl;

        cout << "--------------------------" << endl;
    }
};

// ================= USER CLASS =================
class User {
private:
    int userId;
    string name;

public:
    User(int id, string n) {
        userId = id;
        name = n;
    }

    int getUserId() {
        return userId;
    }

    string getName() {
        return name;
    }

    void displayUser() {
        cout << "User ID : " << userId << endl;
        cout << "Name    : " << name << endl;
        cout << "--------------------------" << endl;
    }
};

// ================= LIBRARY CLASS =================
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:

    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    // Display Books
    void displayBooks() {
        if (books.empty()) {
            cout << "No Books Available\n";
            return;
        }

        for (auto &book : books) {
            book.displayBook();
        }
    }

    // Add User
    void addUser() {
        int id;
        string name;

        cout << "Enter User ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter User Name: ";
        getline(cin, name);

        users.push_back(User(id, name));

        cout << "User Added Successfully!\n";
    }

    // Display Users
    void displayUsers() {
        if (users.empty()) {
            cout << "No Users Found\n";
            return;
        }

        for (auto &user : users) {
            user.displayUser();
        }
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "Enter Book ID to Issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getId() == id) {

                if (book.isIssued()) {
                    cout << "Book Already Issued\n";
                }
                else {
                    book.issueBook();
                    cout << "Book Issued Successfully\n";
                }

                return;
            }
        }

        cout << "Book Not Found\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "Enter Book ID to Return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getId() == id) {

                if (!book.isIssued()) {
                    cout << "Book Already Available\n";
                }
                else {
                    book.returnBook();
                    cout << "Book Returned Successfully\n";
                }

                return;
            }
        }

        cout << "Book Not Found\n";
    }
};

// ================= MAIN FUNCTION =================
int main() {

    Library lib;

    int choice;

    while (true) {

        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Add User\n";
        cout << "4. Display Users\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            lib.addUser();
            break;

        case 4:
            lib.displayUsers();
            break;

        case 5:
            lib.issueBook();
            break;

        case 6:
            lib.returnBook();
            break;

        case 7:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}

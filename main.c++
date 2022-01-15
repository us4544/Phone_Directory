#include <bits/stdc++.h>
using namespace std;

class Telephone_Dir
{
    char f_name[20], l_name[20], phone_no[11], email[20];

public:
    int disp(); //function to display the data

    int get(); //function to input the data

    int input_call(); //function to call the input data function

    int display_call(); //function to call the display data function

    int search(); //function to search the data

    int del(); //function to delete the data

    int mod();       //function to modify the data
} c;                  //object of class Telephone is created as 'c'
int Telephone_Dir::get() //function to input the data
{
    puts("\nEnter  first name :");
    cin >> f_name;
    puts("\nEnter  last name :");
    cin >> l_name;
    puts("\nEnter phone number:");
    cin >> phone_no;
    puts("\nEnter  email address:");
    cin >> email;
}
int Telephone_Dir::disp() //function to display the data
{
    puts("\n first name :");
    puts(f_name);
    puts("\n last name :");
    puts(l_name);
    puts("\n phone number:");
    puts(phone_no);
    puts("\n email address:");
    puts(email);
}
int Telephone_Dir::input_call()
{
    ofstream ofile;
    ofile.open("Tele", ios::app);
    get();                              //here the data is input
    ofile.write((char *)&c, sizeof(c)); //the function now appends the data
    ofile.close();
}
int Telephone_Dir::display_call()
{
    ifstream ifile;
    ifile.open("Tele");
    ifile.seekg(0, ios::beg);
    ifile.read((char *)&c, sizeof(c));
    while (ifile)
    {
        disp(); //here the data is displayed
        ifile.read((char *)&c, sizeof(c));
    }
    ifile.close();
}
int Telephone_Dir::search() //function to search the data
{
    char m[20];
    ifstream ifile("Tele");
    puts("Enter name of Person which has to be searched");
    cin >> m;
    ifile.seekg(0, ios::beg);
    ifile.read((char *)&c, sizeof(c));
    while (ifile)
    {
        if (strcasecmp(m, f_name) == 0)
            disp();
        ifile.read((char *)&c, sizeof(c));
    }
    ifile.close();
}
int Telephone_Dir::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("Tele", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("Enter the name of the Person whose records you want to delete");
    cin >> b;
    ifile.seekg(0, ios::beg);
    ifile.read((char *)&c, sizeof(c));
    while (ifile)
    {
        if (strcasecmp(b, f_name))
            ofile.write((char *)&c, sizeof(c));
        ifile.read((char *)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove("Tele");
    rename("new", "Tele");
}
int Telephone_Dir::mod()
{
    char d[20];
    int p;
    puts("\nEnter name of Person whose record you want to modify\n");
    cin >> d;
    fstream f;
    f.open("Tele", ios::in | ios::out);
    f.seekg(0, ios::beg);
    f.read((char *)&c, sizeof(c));
    int a = f.tellg();
    while (!f.eof())
    {
        if (!strcasecmp(d, f_name))
        {
            puts("\nPress 1 to change  first name\nPress 2 to  change last name\nPress 3 to change phone_no \nPress 4 to change  email address");
            cin >> p;
            switch (p)
            {
            case 1:
                cin >> f_name;
                break;
            case 2:
                cin >> l_name;
                break;
            case 3:
                cin >> phone_no;
                break;
            case 4:
                cin >> email;
                break;
            }
            f.seekg(a - sizeof(c), ios::beg);
            f.write((char *)&c, sizeof(c));
        }
        f.read((char *)&c, sizeof(c));
        a = f.tellg();
    }
    f.close();
}
int main()
{
    int cho;
    char choice;
    do
    {
        cout << "\t      Telephone Directory System";
        cout << "\n ********************************************";
        cout << "\n *  1. View Telephone details                 *";
        cout << "\n *  2. Add new record                         *";
        cout << "\n *  3. Search a Telephone record              *";
        cout << "\n *  4. Delete a Telephone record              *";
        cout << "\n *  5. Modify a Telephone record              *";
        cout << "\n ********************************************";
        cout << "\n Enter your choice: ";
        cin >> cho;

        switch (cho)
        {
        case 1:

            c.display_call();
            break;
        case 2:

            c.input_call();

            break;
        case 3:
            c.search();
            break;
        case 4:
            c.del();
            break;
        case 5:
            c.mod();
            break;
        default:
        {
            cout << "\nerror!";
        }
        break;
        }
        cout << "\ncontinue? (y/n)\n";
        cin >> choice;
    } while (choice == 'y');
    cout << "\nGood bye";
    return 0;
}

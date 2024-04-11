#include <iostream>
#include <string>
using namespace std;
struct word
{
       char a, b;
};
word mas[20];
int n;
int index;
int plu ( string str, char a, char b )
{
    int rez=0;
    int a_c=0, b_c=0;
    for ( int i=0; i<str.length(); i++ )
    {
        if ( str[i]==a )
           a_c++;
        else if ( str[i]==b )
           b_c++;
        else
        {
            rez+=min(a_c, b_c);
            a_c=0;
            b_c=0;
        }
    }
    rez+=min(a_c, b_c);
    return rez;
}
int main() 
{
    string str;
    cin >> str;
    int rez=0;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        cin >> mas[i].a >> mas[i].b;
        rez+=plu(str, mas[i].a, mas[i].b);
    }
    cout << rez;
    cin >> n;
    return 0;
}
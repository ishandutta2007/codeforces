#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string rez=str;
    int p=0, s=0;
    for ( int i=0; i<str.length(); i++ )
    {
        if ( str[i]<='Z' )
        {
             p++;
             str[i]+='a'-'A';
        }
        else
        {
            str[i]-='a'-'A';
            if ( i==0 )
               s++;
            else
                s+=2;
        }
    }
    if ( s==1||s==0 )
    cout << str;
    else
    cout << rez;
    return 0;
}
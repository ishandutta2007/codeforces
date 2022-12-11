#include <iostream>
#include <string>
using namespace std;
int mas[1000];
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    for ( int i=0; i<str1.length(); i++ )
    {
        mas[int(str1[i])]++;
    }
    for ( int i=0; i<str2.length(); i++ )
    {
        mas[int(str2[i])]++;
    }
    string str3;
    cin >> str3;
    for ( int i=0; i<str3.length(); i++ )
    {
        mas[int(str3[i])]--;
        if ( mas[int(str3[i])]<0 )
        {
             cout << "NO";
             return 0;
        }
    }
    for ( int i=0; i<1000; i++ )
    {
        if ( mas[i]!=0 )
        {
             cout << "NO";
             return 0;
        }
    }
    cout << "YES";
    return 0;
}
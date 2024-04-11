#include <iostream>
#include <string>
using namespace std;
int chisla[1000];
int main()
{
    string str;
    cin >> str;
    int four=0, seven=0;
    for ( int i=0; i<str.length(); i++ )
    {
        if ( str[i]=='4' )
           four++;
        else if ( str[i]=='7' )
             seven++;
    }
    if ( four>=seven&&four>0 )
       cout << 4;
    else if ( seven>four )
        cout << 7;
    else
        cout << -1;
    return 0;
}
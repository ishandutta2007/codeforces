#include <iostream>
#include <algorithm>
using namespace std;
char f[100], s[100];
int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> f[i];
    for ( int i = 0; i < n; i++ )
        cin >> s[i];
    sort(f, f + n);
    sort(s, s + n);
    bool h = false, t = false;
    for ( int i = 0; i < n; i++ )
    {
        if ( f[i] > s[i] )
             t = true;
        if ( s[i] > f[i] )
             h = true;
        if ( s[i] == f[i] )
        {
             h = true;
             t = true;
        }
    }
    if ( h && t )
       cout << "NO";
    else
        cout << "YES";
    cin >> n;
    return 0; 
}
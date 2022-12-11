#include <iostream>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    if ( a.length() != b.length() )
    {
        cout << "NO";
        return 0;
    }
    char sumbol1, sumbol2;
    bool f = false;
    int count = 0;
    for ( int i = 0; i < a.length(); i++ )
    {
        if ( a[i] != b[i] )
        {
            if ( count > 1 )
            {
                cout << "NO";
                return 0;
            }
            if ( !f )
                sumbol1 = a[i], sumbol2 = b[i];
            else
            {
                if ( sumbol1 != b[i] || sumbol2 != a[i] ) 
                {
                    cout << "NO";
                    return 0;
                }
            }
            f = true;
            count++;
        }
    }
    if ( count == 2 )
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
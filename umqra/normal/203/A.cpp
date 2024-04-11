#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int x, t, a, b, da, db; 
    cin >> x >> t >> a >> b >> da >> db;
    if ( !x )
    {
        cout << "YES";
        return 0;
    }
    for ( int i = 0; i < t; i++ )
    {
        for ( int s = 0; s < t; s++ )
        {
            if ( a - da * i == x || b - db * s == x || a + b - da * i - db * s == x )
            {
                cout << "YES";  
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
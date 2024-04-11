#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while(tt--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        if(y == 0)
        {
            cout << n/x*x << endl;
            continue;
        }
        if(n % x == 0)
        {
            if(n-x+y > n) cout << n << endl;
            else cout << n-x+y << endl;
        }
        else if(n/x*x+y > n) cout << n/x*x+y-x << endl;
        else cout << n/x*x+y << endl;
    }
}
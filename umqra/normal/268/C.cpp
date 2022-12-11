#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    int k = min(n, m);
    int x = 0, y = k;
    cout << k + 1 << endl;
    for (int i = 0; i <= k; i++)
    {
        cout << x << ' ' << y << endl;
        x++;
        y--;
    }


    return 0;
}
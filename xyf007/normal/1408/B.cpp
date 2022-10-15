#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k, a[200001];
int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int sz = unique(a + 1, a + n + 1) - a - 1;
        if (sz <= k)
        {
            cout << 1 << '\n';
        }
        else
        {
            sz -= k;
            if (k == 1)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << (sz - 1) / (k - 1) + 2 << '\n';
        }
    }
    return 0;
}
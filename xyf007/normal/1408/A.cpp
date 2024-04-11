#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[3][101], ans[101];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[0][i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[1][i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[2][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[j][i] != ans[i - 1])
                {
                    ans[i] = a[j][i];
                    break;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (a[i][n] != ans[n - 1] && a[i][n] != ans[1])
            {
                ans[n] = a[i][n];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
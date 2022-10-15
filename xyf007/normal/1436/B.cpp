#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, p[100001], tot, ans[101][101];
bool not_prime[100001];
void init()
{
    not_prime[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        if (!not_prime[i])
        {
            p[++tot] = i;
        }
        for (int j = 1; j <= tot && i * p[j] <= 100000; j++)
        {
            not_prime[i * p[j]] = 1;
            if (!(i % p[j]))
            {
                break;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[i][j] = 1;
            }
        }

        int t = 0;
        while (not_prime[n - t])
        {
            t++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < t; j++)
            {
                ans[i][(i + j - 1) % n + 1] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
constexpr int MOD = 998244353;
int n, m, a[200001], w[200001], dp[3001][3001], sum[2], inv[10001], ans[2];
int ksm(int a, int b)
{
    int s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * static_cast<long long>(a) % MOD;
        }
        a = a * static_cast<long long>(a) % MOD;
        b >>= 1;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum[a[i]] += w[i];
    }
    for (int i = -m; i <= m; i++)
    {
        inv[i + m] = ksm((sum[0] + sum[1] + i + MOD) % MOD, MOD - 2);
    }
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * static_cast<long long>(sum[0] - j) % MOD * inv[i - j + m] % MOD) % MOD;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * static_cast<long long>(sum[1] + i) % MOD * inv[i - j + m] % MOD) % MOD;
        }
    }
    for (int i = 0; i <= m; i++)
    {
        ans[0] = (ans[0] + dp[m - i][i] * static_cast<long long>(sum[0] - i) % MOD) % MOD;
        ans[1] = (ans[1] + dp[i][m - i] * static_cast<long long>(sum[1] + i) % MOD) % MOD;
    }
    ans[0] = ans[0] * static_cast<long long>(ksm(sum[0], MOD - 2)) % MOD;
    ans[1] = ans[1] * static_cast<long long>(ksm(sum[1], MOD - 2)) % MOD;
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] * static_cast<long long>(ans[a[i]]) % MOD << '\n';
    }
    return 0;
}
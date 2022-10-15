#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
constexpr int MOD = 1e9 + 7;
struct Edge
{
    int to, nxt;
} e[3001];
int n, d, E, head[3001], dp[3001][3001], sum[3001][3001], C[3001][3001], g[3001], inv[3001];
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void dfs(int u)
{
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        dfs(v);
        for (int j = 1; j <= n; j++)
        {
            dp[u][j] = dp[u][j] * static_cast<long long>(sum[v][j]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum[u][i] = (sum[u][i - 1] + dp[u][i]) % MOD;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    memset(head, -1, sizeof(head));
    std::cin >> n >> d;
    int fa;
    for (int i = 2; i <= n; i++)
    {
        std::cin >> fa;
        add(fa, i);
    }
    for (int i = 1; i <= n; i++)
    {
        std::fill(dp[i] + 1, dp[i] + n + 1, 1);
    }
    dfs(1);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = static_cast<long long>(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (int i = 2; i <= n; i++)
    {
        inv[i] = inv[i] * static_cast<long long>(inv[i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = dp[1][i];
        for (int j = 1; j < i; j++)
        {
            g[i] = (g[i] - C[i - 1][i - j] * static_cast<long long>(g[j]) % MOD + MOD) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= std::min(n, d); i++)
    {
        int tmp = inv[i];
        for (int j = d - i + 1; j <= d; j++)
        {
            tmp = tmp * static_cast<long long>(j) % MOD;
        }
        ans = (ans + tmp * static_cast<long long>(g[i])) % MOD;
    }
    std::cout << ans;
    return 0;
}
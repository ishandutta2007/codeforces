#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int mod = 998244353;
vector<int> g[maxn];
int dp[3][maxn];

void dfs(int x, int p) {
    dp[0][x] = 1, dp[2][x] = 1, dp[1][x] = 0;
    long long a = 1, b = 0;
    for (const int &u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
        int cut = (dp[1][u] + dp[2][u]) % mod;
        dp[1][x] = (1ll * dp[1][x] * (dp[1][u] + cut) + 1ll * dp[0][x] * dp[0][u]) % mod;
        dp[2][x] = 1ll * dp[2][x] * cut % mod;
        dp[0][x] = 1ll * dp[0][x] * (dp[1][u] + cut) % mod;
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    printf("%d\n", (dp[2][0] + dp[1][0]) % mod);
    return 0;
}
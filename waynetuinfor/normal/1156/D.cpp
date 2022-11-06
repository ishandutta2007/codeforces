#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<pair<int, int>> g[maxn];
int dp[2][maxn];

void dfs(int x, int p) {
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first, w = g[x][i].second;
        if (u == p) continue;

        dfs(u, x);

        if (w) 
            dp[1][x] += dp[1][u] + 1 + dp[0][u];
        else 
            dp[0][x] += dp[0][u] + 1;
    }
}

long long dfs2(int x, int p, int d0, int d1) {
    long long res = d0 + d1 + dp[0][x] + dp[1][x];

    int dp0 = d0 + dp[0][x];
    int dp1 = d1 + dp[1][x];
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first, w = g[x][i].second;
        if (u == p) continue;
        
        if (w) 
            dp1 -= dp[1][u] + dp[0][u] + 1;
        else
            dp0 -= dp[0][u] + 1;

        int f0 = 0, f1 = 0;
        if (w)
            f1 = dp0 + dp1 + 1;
        else
            f0 = dp0 + 1;

        res += dfs2(u, x, f0, f1);

        if (w)
            dp1 += dp[1][u] + dp[0][u] + 1;
        else
            dp0 += dp[0][u] + 1;
    }

    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(0, -1);
    printf("%lld\n", dfs2(0, -1, 0, 0));
    return 0; 
}
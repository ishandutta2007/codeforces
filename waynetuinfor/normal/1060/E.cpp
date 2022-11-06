#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long dp[2][maxn];
long long way[2][maxn];
long long ans;
int sz[2][maxn];
vector<int> g[maxn];

void dfs(int x, int p) {
    sz[0][x] = 0;
    long long r0 = 0, r1 = 0;
    for (const int &u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
        r0 += dp[0][x] * sz[1][u] + (sz[1][u] + dp[1][u]) * sz[0][x];
        r0 += dp[1][x] * sz[0][u] + (sz[0][u] + dp[0][u]) * sz[1][x];
        r1 += dp[0][x] * sz[0][u] + (sz[0][u] + dp[0][u]) * sz[0][x];
        r1 += dp[1][x] * sz[1][u] + (sz[1][u] + dp[1][u]) * sz[1][x];
        way[0][x] += sz[0][u] * 1ll * sz[1][x];
        way[0][x] += sz[1][u] * 1ll * sz[0][x];
        way[1][x] += sz[0][u] * 1ll * sz[0][x];
        way[1][x] += sz[1][u] * 1ll * sz[1][x];
        way[0][x] += sz[1][u], way[1][x] += sz[0][u];
        dp[0][x] += dp[1][u] + sz[1][u]; 
        dp[1][x] += dp[0][u] + sz[0][u];
        sz[0][x] += sz[1][u];
        sz[1][x] += sz[0][u];
    }
    sz[0][x]++;
    // printf("dp[0][%d] = %lld\n", x, dp[0][x]);
    // printf("dp[1][%d] = %lld\n", x, dp[1][x]);
    r0 += dp[0][x], r1 += dp[1][x];
    ans += r0 / 2;
    ans += (r1 + way[1][x]) / 2;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    printf("%lld\n", ans);
    return 0;
}
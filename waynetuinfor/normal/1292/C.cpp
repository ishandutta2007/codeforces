#include <bits/stdc++.h>
using namespace std;

const int kN = 3000 + 5;
const long long kInf = 1'000'000'000'000'000'000;
vector<int> g[kN];
int u[kN], v[kN], sz[kN], fa[kN], dep[kN], tin[kN], tout[kN];
long long dp[kN][kN];
bool used[kN][kN];

void DfsSz(int x, int p) {
    static int tk = 0;
    sz[x] = 1;
    fa[x] = p;
    tin[x] = tk++;
    for (int u : g[x]) {
        if (u == p) continue;
        dep[u] = dep[x] + 1;
        DfsSz(u, x);
        sz[x] += sz[u];
    }
    tout[x] = tk;
}

bool IsAnc(int x, int y) {
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

long long Dfs(int x, int y, int n) {
    if (IsAnc(y, x)) swap(x, y);
    if (used[x][y]) return dp[x][y];
    dp[x][y] = 0;
    if (IsAnc(x, y)) {
        int sx = 0, sy = sz[y];
        for (int u : g[x]) {
            if (u == fa[x]) continue;
            if (IsAnc(u, y)) sx = n - sz[u];
        }
        for (int u : g[x]) {
            if (u == fa[x] || !IsAnc(u, y)) dp[x][y] = max(dp[x][y], Dfs(u, y, n));
        }
        for (int v : g[y]) {
            if (v == fa[y]) continue;
            dp[x][y] = max(dp[x][y], Dfs(x, v, n));
        }
        dp[x][y] += 1LL * sx * sy;
    } else {
        int sx = sz[x], sy = sz[y];
        for (int u : g[x]) {
            if (u == fa[x]) continue;
            dp[x][y] = max(dp[x][y], Dfs(u, y, n));
        }
        for (int v : g[y]) {
            if (v == fa[y]) continue;
            dp[x][y] = max(dp[x][y], Dfs(x, v, n));
        }
        dp[x][y] += 1LL * sx * sy;
    }
    used[x][y] = true;
    return dp[x][y];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    DfsSz(0, -1);
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) ans = max(ans, Dfs(u[i], v[i], n));
    printf("%lld\n", ans);
}
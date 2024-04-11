#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e15;
vector<pair<int, int>> g[maxn];
vector<int> outgo;
long long dp[maxn], dt[50][maxn];
int n, m, rev[maxn], dep[maxn], fa[20][maxn];
bool v[maxn];

void dfs(int x, int p, long long c) {
    dep[x] = (~p ? dep[p] + 1 : 0);
    fa[0][x] = p;
    for (int i = 1; (1 << i) <= dep[x]; ++i) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    dp[x] = c;
    v[x] = true;
    bool o = false;
    for (const auto &e : g[x]) {
        int u = e.first, d = e.second;
        if (u == p) continue;
        if (v[u]) {
            o = true;
            continue;
        }
        dfs(u, x, c + d);
    }
    if (o) outgo.push_back(x);
}

void dijk(int x, int z) {
    for (int i = 0; i < n; ++i) dt[z][i] = inf, v[i] = false;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dt[z][x] = 0;
    pq.emplace(0, x);
    while (pq.size()) {
        int x = pq.top().second; pq.pop();
        if (v[x]) continue;
        v[x] = true;
        for (const auto &e : g[x]) {
            int u = e.first, d = e.second;
            if (dt[z][x] + d < dt[z][u]) {
                dt[z][u] = dt[z][x] + d;
                pq.emplace(dt[z][u], u);
            }
        }
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0; i < 20; ++i) {
        if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; --i) {
        if (fa[i][y] != fa[i][x]) {
            y = fa[i][y];
            x = fa[i][x];
        }
        if (x == y) return x;
    }
    return fa[0][x];
}

long long dist(int x, int y) {
    return dp[x] + dp[y] - 2 * dp[lca(x, y)];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, d; scanf("%d %d %d", &x, &y, &d);
        --x, --y;
        g[x].emplace_back(y, d);
        g[y].emplace_back(x, d);
    }
    memset(fa, -1, sizeof(fa));
    dfs(0, -1, 0);
    for (int i = 0; i < (int)outgo.size(); ++i) dijk(outgo[i], i);
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        long long ans = dist(x, y);
        for (int i = 0; i < (int)outgo.size(); ++i) ans = min(ans, dt[i][x] + dt[i][y]);
        printf("%lld\n", ans);
    }
}
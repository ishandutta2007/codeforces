#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct DSU {
    vector<int> p, rk;
    DSU(int n) : p(n), rk(n) {
        iota(all(p), 0);
    }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;
    vector<int> w(m);

    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v >> w[j];
        --u, --v;
        edges.push_back({j, u, v});
    }

    sort(all(edges), [&](auto p, auto q){ return w[p[0]] < w[q[0]]; });

    DSU dsu(n);
    vector<vector<pair<int, int>>> F(n);
    vector<bool> tree(m, false);

    for (auto [j, u, v] : edges) {
        if (dsu.unite(u, v)) {
            tree[j] = true;
            F[u].emplace_back(v, j);
            F[v].emplace_back(u, j);
        }
    }

    constexpr int K = 20;
    vector<array<int, K>> go(n), cost(n), upd(n);
    for (int u = 0; u < n; ++u) fill(all(upd[u]), INF);
    vector<int> e(n), h(n);

    auto dfs = [&](auto& self, int u, int p) -> void {
        for (int x = 0; x + 1 < K; ++x) {
            int v = go[u][x];
            go[u][x + 1] = go[v][x];
            cost[u][x + 1] = max(cost[u][x], cost[v][x]);
        }
        for (auto [v, j] : F[u]) if (v != p) {
            h[v] = h[u] + 1, e[v] = j;
            cost[v][0] = w[j], go[v][0] = u;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, 0);

    vector<int> ans(m);
    for (auto [j, u, v] : edges) {
        if (tree[j]) continue;
        if (h[u] < h[v]) swap(u, v);
        int d = h[u] - h[v];
        for (int x = 0; x < K; ++x) {
            if (d >> x & 1) {
                ans[j] = max(ans[j], cost[u][x]);
                upd[u][x] = min(upd[u][x], w[j]);
                u = go[u][x];
            }
        }
        if (u == v) continue;
        for (int x = K - 1; x >= 0; --x) {
            if (go[u][x] != go[v][x]) {
                for (auto z : {u, v}) {
                    ans[j] = max(ans[j], cost[z][x]);
                    upd[z][x] = min(upd[z][x], w[j]);
                }
                u = go[u][x], v = go[v][x];
            }
        }
        ans[j] = max({ans[j], cost[u][0], cost[v][0]});
        for (auto z : {u, v}) {
            ans[j] = max(ans[j], cost[z][0]);
            upd[z][0] = min(upd[z][0], w[j]);
        }
    }

    for (int x = K - 2; x >= 0; --x) {
        for (int u = 0; u < n; ++u) {
            for (auto v : {u, go[u][x]}) {
                upd[v][x] = min(upd[v][x], upd[u][x + 1]);
            }
        }
    }

    for (int u = 1; u < n; ++u) {
        ans[e[u]] = upd[u][0];
    }

    for (int j = 0; j < m; ++j) {
        if (ans[j] == INF) ans[j] = 0;
        --ans[j];
        cout << ans[j] << "\n "[j + 1 < m];
    }

    exit(0);
}
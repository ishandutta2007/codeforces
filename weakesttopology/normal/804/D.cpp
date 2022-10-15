#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> E(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> h(n), mx(n), color(n, -1), cost(n), up(n), diam(n), sz(n);
    auto dfs1 = [&](auto&& self, int u) -> void {
        mx[u] = h[u];
        int x = color[u];
        diam[x] = max(diam[x], h[u]), sz[x] += 1;
        for (auto v : E[u]) if (color[v] == -1) {
            h[v] = h[u] + 1, color[v] = color[u];
            self(self, v);
            int d = mx[u] + mx[v] - 2 * h[u];
            diam[x] = max(diam[x], d);
            mx[u] = max(mx[u], mx[v]);
        }
    };
    auto dfs2 = [&](auto&& self, int u) -> void {
        cost[u] = max(mx[u] - h[u], up[u]);
        int mx_up = up[u];
        for (auto v : E[u]) if (h[v] > h[u]) {
            up[v] = max(up[v], mx_up + 1);
            mx_up = max(mx_up, mx[v] - h[u]);
        }
        reverse(all(E[u]));
        mx_up = up[u];
        for (auto v : E[u]) if (h[v] > h[u]) {
            up[v] = max(up[v], mx_up + 1);
            mx_up = max(mx_up, mx[v] - h[u]);
            self(self, v);
        }
    };
    vector<vector<ll>> suffsum(n), suffcnt(n), cnt(n);
    for (int u = 0; u < n; ++u) {
        if (color[u] == -1) {
            color[u] = u;
            dfs1(dfs1, u);
            dfs2(dfs2, u);
            suffsum[u].assign(diam[u] + 1, 0);
            cnt[u].assign(diam[u] + 1, 0);
            suffcnt[u].assign(diam[u] + 1, 0);
        }
        suffsum[color[u]][cost[u]] += cost[u];
        cnt[color[u]][cost[u]] += 1;
        suffcnt[color[u]][cost[u]] += 1;
    }

    for (int u = 0; u < n; ++u) if (u == color[u]) {
        for (int x = diam[u] - 1; x >= 0; --x) {
            suffcnt[u][x] += suffcnt[u][x + 1];
            suffsum[u][x] += suffsum[u][x + 1];
        }
    }

    map<pair<int, int>, ll> memo;
    cout << setprecision(10) << fixed;
    for (int z = 0; z < q; ++z) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        u = color[u], v = color[v];
        if (u > v) swap(u, v);
        pair<int, int> p(u, v);

        if (u == v) {
            cout << -1 << endl;
            continue;
        }

        ll tot = 0;
        if (memo.count(p)) tot = memo[p];
        else {
            if (diam[u] > diam[v]) swap(u, v);
            int D = max(diam[u], diam[v]);
            for (int x = D - diam[v]; x <= diam[u]; ++x) {
                tot += cnt[u][x] * (suffcnt[v][D - x] * (x + 1) + suffsum[v][D - x]);
                tot += cnt[u][x] * (sz[v] - suffcnt[v][D - x]) * D;
            }
            memo[p] = tot;
        }
        double res = double(tot) / (double(sz[u]) * sz[v]);
        cout << res << endl;
    }

    exit(0);
}
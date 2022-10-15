#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y){ return y < x ? (x = y, true) : false; }

struct DSU {
    vector<int> deg, p, rk;
    DSU(int n) : deg(n), p(n), rk(n) {
        iota(all(p), 0);
    }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        deg[u] += 1, deg[v] += 1;
        u = find(u), v = find(v);
        if (u == v) return;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
    }
};

const int L = 1e7, R = 1e9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> unif(L, R);

// trees will most likely have O(log(n)) height
// also, connected graphs will have O(log(n)) diameter
// number of edges is not exact, specially with small graphs
// make sure to relabel, catches stupid bugs
// 0-based

auto tree_generator(int n) {
    vector<pair<int, int>> edges;
    for (int u = 1; u < n; ++u) edges.emplace_back(unif(rng) % u, u);
    return edges;
}

auto graph_generator(int n, int m) {
    vector<pair<int, int>> edges;
    for (int j = 0; j < m; ++j) {
        int u = unif(rng) % n, v = unif(rng) % n;
        if (u == v) continue;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }
    sort(all(edges)), edges.erase(unique(all(edges)), end(edges));
    return edges;
}

auto connected_graph_generator(int n, int m) {
    assert(m >= n - 1);

    auto tree = tree_generator(n);
    auto edges = graph_generator(n, m - (n - 1));

    edges.insert(end(edges), all(tree));
    sort(all(edges)), edges.erase(unique(all(edges)), end(edges));

    return edges;
}

void relabel(int n, auto& edges) {
    vector<int> label(n, 0);
    iota(all(label), 0);
    shuffle(all(label), rng);
    for (auto& [u, v] : edges) u = label[u], v = label[v];
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        for (int t = 0; t < 2; ++t, swap(u, v)) E[u].push_back(v);
    }

    //int n = 6;
    //auto edges = tree_generator(n);
    //relabel(n, edges);
    //vector<vector<int>> E(n);
    //vector<int> deg(n);
    //for (auto& [u, v] : edges) {
    //    cerr << u << " " << v << endl;
    //    for (int t = 0; t < 2; ++t, swap(u, v)) {
    //        E[u].push_back(v);
    //        deg[u] += 1;
    //    }
    //}

    vector<array<int, 4>> dp(n);
    auto dfs = [&](auto& self, int u, int p) -> void {
        fill(2 + all(dp[u]), -1);
        int sum = 0;
        for (auto& v : E[u]) {
            if (v == p) swap(v, E[u].back());
            if (v != p) {
                self(self, v, u);
                sum += dp[v][0];
            }
        }
        if (p != -1) E[u].pop_back();
        sort(all(E[u]), [&](int u, int v){ return dp[u][1] - dp[u][0] < dp[v][1] - dp[v][0]; });
        int deg = (int)size(E[u]);
        if (deg >= 1) {
            int v = E[u][0];
            dp[u][0] = dp[u][1] = sum + dp[v][1] - dp[v][0] + deg - 1;
            dp[u][2] = v;
        }
        if (deg >= 2) {
            int w = E[u][1];
            if (chmin(dp[u][0], dp[u][1] - 1 + dp[w][1] - dp[w][0])) dp[u][3] = w;
        }
    };
    dfs(dfs, 0, -1);

    vector<array<int, 2>> remove;
    DSU dsu(n);

    auto recover = [&](auto& self, int u, int t) -> void {
        int keep[2] = { dp[u][2], -1 };
        if (t == 0) keep[1] = dp[u][3];
        for (auto v : E[u]) {
            if (keep[0] == v || keep[1] == v) {
                dsu.unite(u, v);
                self(self, v, 1);
            }
            else {
                remove.push_back({u, v});
                self(self, v, 0);
            }
        }
    };
    recover(recover, 0, 0);

    vector<array<int, 2>> intervals(n, {-1, -1});
    for (int u = 0; u < n; ++u) {
        int p = dsu.find(u);
        if (dsu.deg[u] <= 1) {
            for (auto& v : intervals[p]) {
                if (v == -1) {
                    v = u;
                    break;
                }
            }
        }
    }

    auto iter = remove_if(all(intervals), [&](auto vec){ return vec[0] == -1 && vec[1] == -1; });
    intervals.erase(iter, end(intervals));

    //debug(size(intervals));
    //debug(size(remove));
    assert(size(intervals) == size(remove) + 1);
    //for (auto [u, v] : intervals) {
    //    cerr << u << " " << v << endl;
    //    debug(dsu.deg[u]);
    //    debug(dsu.deg[v]);
    //}

    vector<array<int, 2>> add;

    int k = (int)size(intervals);
    for (int j = 0; j + 1 < k; ++j) {
        bool taken = false;
        for (auto u : intervals[j]) if (u != -1) {
            for (auto v : intervals[j + 1]) if (v != -1) {
                if (not taken && dsu.deg[u] < 2 && dsu.deg[v] < 2) {
                    dsu.unite(u, v);
                    add.push_back({u, v});
                    taken = true;
                }
            }
        }
    }

    //debug(size(add));
    //debug(size(remove));
    assert(size(add) == size(remove));
    cout << k - 1 << endl;
    for (int j = 0; j < k - 1; ++j) {
        cout << remove[j][0] + 1 << " " << remove[j][1] + 1 << " " << add[j][0] + 1 << " " << add[j][1] + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}
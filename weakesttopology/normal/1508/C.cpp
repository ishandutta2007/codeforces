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
    DSU(int n) : p(n), rk(n, 0) { iota(all(p), 0); }
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

    vector<vector<int>> E(n);
    vector<array<int, 3>> edges(m);

    int xorsum  = 0;
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
        --u, --v;
        xorsum ^= w;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }

    DSU dsu(n);

    vector<bool> vis(n, false);
    bool cycle = false;

    for (int u = 0; u < n && not cycle; ++u) {
        vis[u] = true;
        for (auto v : E[u]) vis[v] = true;
        for (int v = u + 1; v < n; ++v) {
            if (vis[v]) continue;
            if (not dsu.unite(u, v)) {
                cycle = true;
                break;
            }
        }
        vis[u] = false;
        for (auto v : E[u]) vis[v] = false;
    }

    debug(xorsum);
    debug(cycle);

    if (cycle) xorsum = 0;

    set<int> R, S;
    for (int u = 0; u < n; ++u) S.insert(u);

    queue<int> q;
    while (not empty(S)) {
        q.push(*begin(S));
        S.erase(begin(S));

        while (not empty(q)) {
            int u = q.front();
            q.pop();

            for (auto v : E[u]) R.insert(S.extract(v));
            for (auto v : S) {
                dsu.unite(u, v);
                q.push(v);
            }
            S.clear();
            swap(R, S);
        }
    }

    vector<array<int, 3>> extra_edges;

    ll cost = 0;

    sort(all(edges));
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            cost += w;
            extra_edges.push_back({u, v, w});
        }
    }

    dsu = DSU(n);
    for (auto [u, v, w] : extra_edges) dsu.unite(u, v);

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            xorsum = min(xorsum, w);
            break;
        }
    }
    cost += xorsum;

    cout << cost << endl;

    exit(0);
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
struct DSU {
    vector<int> p, rk;
    vector<ll> cost;
    DSU(int n) : p(n), rk(n), cost(n) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        return p[u] == u ? u : find(p[u]);
    }
    ll query(int u, int v) {
        ll res = 0;
        while (u != v) {
            if (rk[u] < rk[v]) swap(u, v);
            res = max(res, cost[v]);
            v = p[v];
        }
        return res;
    }
    void unite(int u, int v, ll x) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, cost[v] = x, rk[u] += (rk[u] == rk[v]);
    }
};
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<pair<int, ll>>> E(n);
    vector<tuple<ll, int, int>> edges(m);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
        --u, --v;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    vector<ll> dist(n, inf);
    vector<int> p(n, -1);
    priority_queue<pair<ll, int>> pq;
    for (int u = 0; u < k; ++u) {
        dist[u] = 0;
        pq.emplace(0, u);
    }
    DSU dsu(n);
    while (not empty(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (-d > dist[u]) continue;
        if (p[u] != -1) {
            dsu.unite(u, p[u], 0LL);
        }
        for (auto [v, w] : E[u]) {
            if (chmin(dist[v], dist[u] + w)) {
                p[v] = u;
                pq.emplace(-dist[v], v);
            }
        }
    }
    for (auto& [w, u, v] : edges) {
        w += dist[u] + dist[v];
    }
    sort(begin(edges), end(edges));
    for (auto [w, u, v] : edges) {
        dsu.unite(u, v, w);
    }
    for (int z = 0; z < q; ++z) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << dsu.query(a, b) << '\n';
    }
    exit(0);
}
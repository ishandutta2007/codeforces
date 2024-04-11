#include <bits/stdc++.h>
using namespace std;
struct DSU {
    int N;
    vector<int> p, rk;
    DSU(int N) : p(N), rk(N) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, rk[u] += (rk[u] == rk[v]);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M[2];
    cin >> N >> M[0] >> M[1];
    DSU dsu[2] = {DSU(N), DSU(N)};
    for (int t : {0, 1}) {
        for (int j = 0; j < M[t]; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            dsu[t].unite(u, v);
        }
    }
    vector<array<int, 2>> edges;
    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < u; ++v) {
            bool good = true;
            for (int t : {0, 1}) {
                if (dsu[t].find(u) == dsu[t].find(v)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                for (int t : {0, 1}) {
                    dsu[t].unite(u, v);
                }
                edges.push_back({u, v});
            }
        }
    }
    cout << size(edges) << '\n';
    for (auto [u, v] : edges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    exit(0);
}
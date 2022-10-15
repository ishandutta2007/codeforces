#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 'heavy' matroid should be N
template<typename Matroid1, typename Matroid2>
vector<int> matroid_intersection(int n, Matroid1& M, Matroid2& N) {
    vector<bool> b(n);
    vector<int> I[2];
    while (true) {
        for (int t : {0, 1}) I[t].clear();
        for (int u = 0; u < n; ++u) {
            I[b[u]].push_back(u);
        }
        M.build(I[1]), N.build(I[1]);
        vector<bool> target(n), pushed(n);
        queue<int> q;
        for (auto u : I[0]) {
            target[u] = N.oracle(u);
            if (M.oracle(u)) {
                pushed[u] = true;
                q.push(u);
            }
        }
        vector<int> p(n, -1);
        bool converged = true;
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            if (target[u]) {
                converged = false;
                for (int v = u; v != -1; v = p[v]) b[v] = !b[v];
                break;
            }
            for (auto v : I[!b[u]]) {
                if (pushed[v]) continue;
                if ((b[u] && M.oracle(u, v)) || (b[v] && N.oracle(v, u))) {
                    p[v] = u;
                    pushed[v] = true;
                    q.push(v);
                }
            }
        }
        if (converged) break;
    }
    return I[1];
}
struct GraphicMatroid {
    int N, M;
    vector<array<int, 2>> edges;
    vector<vector<int>> E;
    vector<int> component, L, R;
    GraphicMatroid(int N, const vector<array<int, 2>>& edges_) : N(N), M((int)edges_.size()), edges(edges_), E(N), component(N), L(N), R(N) {}
    int timer = 0;
    void dfs(int u) {
        L[u] = timer++;
        for (auto v : E[u]) {
            if (L[v] != -1) continue;
            component[v] = component[u];
            dfs(v);
        }
        R[u] = timer - 1;
    }
    void build(const vector<int>& I) {
        timer = 0;
        for (int u = 0; u < N; ++u) {
            E[u].clear();
            L[u] = -1;
        }
        for (auto e : I) {
            auto [u, v] = edges[e];
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for (int u = 0; u < N; ++u) {
            if (L[u] != -1) continue;
            component[u] = u;
            dfs(u);
        }
    }
    bool is_ancestor(int u, int v) const {
        return L[u] <= L[v] && L[v] <= R[u];
    }
    bool oracle(int e) const {
        return component[edges[e][0]] != component[edges[e][1]];
    }
    bool oracle(int e, int f) const {
        if (oracle(f)) return true;
        int u = edges[e][L[edges[e][0]] < L[edges[e][1]]];
        return is_ancestor(u, edges[f][0]) != is_ancestor(u, edges[f][1]);
    }
};
struct PartitionMatroid {
    vector<int> cap, color, d;
    PartitionMatroid(const vector<int>& cap, const vector<int>& color) : cap(cap), color(color), d(size(cap)) {}
    void build(const vector<int>& I) {
        fill(begin(d), end(d), 0);
        for (auto u : I) {
            ++d[color[u]];
        }
    }
    bool oracle(int u) const {
        return d[color[u]] < cap[color[u]];
    }
    bool oracle(int u, int v) const {
        return color[u] == color[v] || oracle(v);
    }
};
struct DSU {
    vector<int> p, rk;
    DSU(int N) : p(N), rk(N) {
        iota(begin(p), end(p), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) {
            cin >> g[i];
        }
        auto id = [&](int i, int j) { return m * i + j; };
        vector<array<int, 2>> edges;
        vector<int> color;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'X') continue;
                cnt += (i + j) % 2 == 0;
                int u = id(i, j);
                if (i + 1 < n && g[i + 1][j] != 'X') {
                    int v = id(i + 1, j);
                    edges.push_back({u, v});
                    color.push_back((i + j) % 2 ? v : u);
                }
                if (j + 1 < m && g[i][j + 1] != 'X') {
                    int v = id(i, j + 1);
                    edges.push_back({u, v});
                    color.push_back((i + j) % 2 ? v : u);
                }
            }
        }
        int N = n * m, M = (int)size(edges);
        vector<int> cap(N, 2);
        cap[0] = 0;
        GraphicMatroid G(N, edges);
        PartitionMatroid P(cap, color);
        auto I = matroid_intersection(M, P, G);
        if ((int)size(I) < 2 * (cnt - 1)) {
            cout << "NO\n";
        }
        else {
            DSU dsu(N);
            vector<vector<array<bool, 2>>> E(n, vector<array<bool, 2>>(m));
            for (auto e : I) {
                auto [u, v] = edges[e];
                dsu.unite(u, v);
                E[u / m][u % m][u % m == v % m] = true;
            }
            for (auto [u, v] : edges) {
                if (dsu.unite(u, v)) {
                    E[u / m][u % m][u % m == v % m] = true;
                }
            }
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << g[i][j];
                    if (j + 1 < m) {
                        cout << " O"[E[i][j][0]];
                    }
                }
                cout << '\n';
                if (i + 1 < n) {
                    for (int j = 0; j < m; ++j) {
                        cout << " O"[E[i][j][1]];
                        if (j + 1 < m) cout << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
    exit(0);
}
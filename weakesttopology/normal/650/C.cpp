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
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        p[v] = u, rk[u] = rk[v] == rk[u];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    for (auto& v : a) {
        v.resize(m);
        for (auto& x : v) cin >> x;
    }

    int N = n * m;
    vector<vector<int>> E(N);
    DSU dsu(N);

    auto unite = [&](auto line) {
        sort(all(line));
        int k = (int)size(line);
        for (int z = 0; z + 1 < k; ++z) {
            if (line[z + 1].first == line[z].first) {
                dsu.unite(line[z + 1].second, line[z].second);
            }
        }
    };
    auto add_edges = [&](auto line) {
        sort(all(line));
        int k = (int)size(line);
        for (int z = 0; z + 1 < k; ++z) {
            int u = dsu.find(line[z].second), v = dsu.find(line[z + 1].second);
            if (u != v) E[u].push_back(v);
        }
    };

    for (int j = 0; j < m; ++j) {
        vector<pair<int, int>> col;
        for (int i = 0; i < n; ++i) col.emplace_back(a[i][j], i * m + j);
        unite(col);
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> row;
        for (int j = 0; j < m; ++j) row.emplace_back(a[i][j], i * m + j);
        unite(row);
    }
    for (int j = 0; j < m; ++j) {
        vector<pair<int, int>> col;
        for (int i = 0; i < n; ++i) col.emplace_back(a[i][j], i * m + j);
        add_edges(col);
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> row;
        for (int j = 0; j < m; ++j) row.emplace_back(a[i][j], i * m + j);
        add_edges(row);
    }

    vector<int> indeg(N, 0);
    for (int u = 0; u < N; ++u) {
        for (auto v : E[u]) indeg[v] += 1;
    }
 
    queue<int> q;
    vector<int> rk(N, 0);
 
    for (int u = 0; u < N; ++u) {
        if (indeg[u] == 0) q.push(u);
    }
 
    while (not empty(q)) {
        int u = q.front();
        q.pop();
        for (auto v : E[u]) {
            rk[v] = max(rk[v], rk[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = 1 + rk[dsu.find(i * m + j)];
            cout << a[i][j] << "\n "[j + 1 < m];
        }
    }

    exit(0);
}
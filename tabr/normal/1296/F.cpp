#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct LCA {
    vector<vector<int>> g, par;
    vector<int> depth;
    int n, logn;

    LCA(vector<vector<int>> g_, int root = 0)
        : g(g_) {
        n = g.size();
        logn = log2(n) + 1;
        depth.resize(n + 1);
        par.resize(logn, vector<int>(n + 1));
        dfs(root, -1, 0);
        for (int i = 0; i < logn - 1; i++)
            for (int j = 0; j <= n; j++) {
                if (par[i][j] < 0)
                    par[i + 1][j] = -1;
                else
                    par[i + 1][j] = par[i][par[i][j]];
            }
    }

    void dfs(int v, int p, int d = 0) {
        par[0][v] = p;
        depth[v] = d;
        for (auto u : g[v]) {
            if (u != p) {
                dfs(u, v, d + 1);
            }
        }
    }
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = 0; i < logn; i++) {
            if ((depth[v] - depth[u]) >> i & 1) {
                v = par[i][v];
            }
        }
        if (u == v) return u;
        for (int i = logn - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(depth[w] - depth[v]) + abs(depth[w] - depth[u]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> e;
    vector<int> f(n - 1, 1000001);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[pair<int, int>(a, b)] = i;
        e[pair<int, int>(b, a)] = i;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> x(m);
    for (int i = 0; i < m; i++) {
        int a, b, gf;
        cin >> a >> b >> gf;
        a--, b--;
        x[i] = {gf, {a, b}};
    }
    sort(x.rbegin(), x.rend());
    LCA t(g);
    for (int i = 0; i < m; i++) {
        int a, b;
        tie(a, b) = x[i].second;
        int c = t.lca(a, b);
        int gf = x[i].first;
        bool ok = false;
        for (int j = 0; j < 2; j++) {
            while (a != c) {
                int to = t.par[0][a];
                int id = e[pair<int, int>(a, to)];
                if (f[id] == 1000001 || f[id] == gf) {
                    f[id] = gf;
                    ok = true;
                }
                a = to;
            }
            swap(a, b);
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i : f) {
        cout << min(1000000, i) << " ";
    }
    cout << endl;
    return 0;
}
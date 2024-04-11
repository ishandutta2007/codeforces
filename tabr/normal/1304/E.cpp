#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

vector<vector<int>> g;

struct LCA {
    vector<vector<int>> par;
    vector<int> depth;
    int logn;

    LCA(int n, int root) {
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
        for (auto u : g[v])
            if (u != p)
                dfs(u, v, d + 1);
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v])
            swap(u, v);
        for (int i = 0; i < logn; i++)
            if ((depth[v] - depth[u]) >> i & 1)
                v = par[i][v];
        if (u == v)
            return u;
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
    g.resize(n);
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    LCA dt(n, 0);
    int qq;
    cin >> qq;
    while (qq--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;
        int ab = dt.dist(a, b);
        int xy = dt.dist(x, y);
        int ax = dt.dist(a, x), ay = dt.dist(a, y), bx = dt.dist(b, x), by = dt.dist(b, y);
        if (k >= ab && (k - ab) % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }
        int d = min(ax + by + 1, bx + ay + 1);
        if (k >= d && (k - d) % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}
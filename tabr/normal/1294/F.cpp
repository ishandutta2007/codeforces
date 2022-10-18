#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

vector<vector<int>> g(202000);

pair<int, pair<int, int>> tdfs(int v, int p) {
    pair<int, pair<int, int>> d = {1, {v, v}};
    for (auto u : g[v])
        if (u != p) {
            pair<int, pair<int, int>> d2 = tdfs(u, v);
            d2.first++;
            d2.second.first = v;
            d = max(d, d2);
        }
    return d;
}

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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    pair<int, pair<int, int>> q = tdfs(0, -1);
    pair<int, pair<int, int>> w = tdfs(q.second.second, -1);
    LCA l(n, q.second.second);
    int a = q.second.second, b = w.second.second;
    int cnt = 0, c = -1;
    rep(i, 0, n) {
        if (i == a || i == b) continue;
        int sum = l.depth[b] + l.depth[i] - l.depth[l.lca(b, i)];
        if (sum >= cnt) {
            cnt = sum;
            c = i;
        }
    }
    cout << cnt << endl;
    a++, b++, c++;
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
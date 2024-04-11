#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct hld {
    int n;
    vector<vector<int>> g;
    vector<int> sz;
    vector<int> pv;
    vector<int> pos;
    vector<int> depth;
    vector<int> order;
    vector<int> head;

    hld(vector<vector<int>> _g, int root = 0) : g(_g) {
        n = (int)g.size();
        sz.resize(n);
        pv.resize(n);
        pos.resize(n);
        depth.resize(n);
        head.resize(n);
        pv[root] = -1;
        dfs_sz(root);
        dfs_hld(root);
    }

    void dfs_sz(int v) {
        sz[v] = 1;
        if (!g[v].empty() && g[v][0] == pv[v]) {
            swap(g[v][0], g[v].back());
        }
        for (int &to : g[v]) {
            if (to == pv[v]) {
                continue;
            }
            pv[to] = v;
            depth[to] = depth[v] + 1;
            dfs_sz(to);
            sz[v] += sz[to];
            if (sz[to] > sz[g[v][0]]) {
                swap(to, g[v][0]);
            }
        }
    }

    void dfs_hld(int v) {
        pos[v] = (int)order.size();
        order.emplace_back(v);
        for (int to : g[v]) {
            if (to == pv[v]) {
                continue;
            }
            head[to] = (to == g[v][0] ? head[v] : to);
            dfs_hld(to);
        }
    }

    int lca(int x, int y) {
        while (true) {
            if (pos[x] > pos[y]) {
                swap(x, y);
            }
            if (head[x] == head[y]) {
                return x;
            }
            y = pv[head[y]];
        }
    }

    void apply(int x, int y, bool with_lca, function<void(int, int, bool)> f) {
        int z = lca(x, y);
        int v = x;
        while (v != z) {
            if (depth[head[v]] <= depth[z]) {
                f(pos[z] + 1, pos[v], true);
                break;
            }
            f(pos[head[v]], pos[v], true);
            v = pv[head[v]];
        }
        if (with_lca) {
            f(pos[z], pos[z], false);
        }
        v = y;
        vector<int> visited;
        while (v != z) {
            if (depth[head[v]] <= depth[z]) {
                f(pos[z] + 1, pos[v], false);
                break;
            }
            visited.emplace_back(v);
            v = pv[head[v]];
        }
        for (int i = (int)visited.size() - 1; i >= 0; i--) {
            v = visited[i];
            f(pos[head[v]], pos[v], false);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2);
    vector<vector<vector<int>>> g(2);
    vector<vector<int>> x(2, vector<int>(n));
    for (int l = 0; l < 2; l++) {
        cin >> a[l];
        g[l].resize(a[l]);
        for (int i = 1; i < a[l]; i++) {
            int p;
            cin >> p;
            p--;
            g[l][i].emplace_back(p);
            g[l][p].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> x[l][i];
            x[l][i]--;
        }
    }
    int all = a[0] + a[1] - 2;
    vector<hld> t = {hld(g[0]), hld(g[1])};
    vector<vector<int>> dp(2, vector<int>(1));
    dp[0][0] = t[0].depth[x[0][0]];
    dp[1][0] = t[1].depth[x[1][0]];
    for (int i = 1; i < n; i++) {
        for (int l = 0; l < 2; l++) {
            dp[l].emplace_back(1e9);
            for (int j = 0; j < i; j++) {
                int z = t[l].depth[x[l][i]];
                if (j != 0) {
                    int v = t[l].lca(x[l][i], x[l][j - 1]);
                    z -= t[l].depth[v];
                }
                dp[l][i] = min(dp[l][i], dp[l ^ 1][j] + z);
            }
        }
        for (int l = 0; l < 2; l++) {
            int v = t[l].lca(x[l][i], x[l][i - 1]);
            int add = t[l].depth[x[l][i]] - t[l].depth[v];
            for (int j = 0; j < i; j++) {
                dp[l][j] += add;
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[i][j]);
        }
    }
    debug(dp);
    cout << all - ans << '\n';
    return 0;
}
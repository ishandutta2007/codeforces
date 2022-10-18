#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct tree {
    struct edge {
        int from;
        int to;
        T cost;
        edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}
    };

    int n;
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> pv;
    vector<int> pe;
    vector<int> depth;
    vector<int> sz;
    vector<int> order;
    vector<int> beg;
    vector<int> end;
    vector<T> dist;

    tree(int _n) : n(_n) {
        init();
    }
    void init() {
        g.resize(n);
        pv.assign(n, -1);
        pe.assign(n, -1);
        depth.assign(n, -1);
        sz.assign(n, 0);
        order.clear();
        beg.assign(n, -1);
        end.assign(n, -1);
        dist.resize(n, 0);
    }
    int add(int from, int to, T cost = 1) {
        int id = (int)edges.size();
        g[from].emplace_back(id);
        g[to].emplace_back(id);
        edges.emplace_back(from, to, cost);
        return id;
    }
    void do_dfs(int v) {
        beg[v] = (int)order.size();
        order.emplace_back(v);
        sz[v] = 1;
        for (int id : g[v]) {
            if (id == pe[v]) {
                continue;
            }
            edge e = edges[id];
            int to = e.from ^ e.to ^ v;
            pv[to] = v;
            pe[to] = id;
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int)order.size();
    }
    void dfs(int v) {
        pv[v] = -1;
        pe[v] = -1;
        depth[v] = 0;
        dist[v] = 0;
        do_dfs(v);
    }

    int h;
    vector<vector<int>> p;
    inline void build_lca() {
        int maxd = *max_element(depth.begin(), depth.end());
        h = 1;
        while ((1 << h) <= maxd) {
            h++;
        }
        p.assign(n, vector<int>(h));
        for (int i = 0; i < n; i++) {
            p[i][0] = pv[i];
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i < n; i++) {
                p[i][j] = (p[i][j - 1] == -1 ? -1 : p[p[i][j - 1]][j - 1]);
            }
        }
    }
    inline bool anc(int x, int y) {
        return (beg[x] <= beg[y] && end[y] <= end[x]);
    }
    inline int lca(int x, int y) {
        if (anc(x, y)) {
            return x;
        }
        if (anc(y, x)) {
            return y;
        }
        for (int j = h - 1; j >= 0; j--) {
            if (p[x][j] != -1 && !anc(p[x][j], y)) {
                x = p[x][j];
            }
        }
        return p[x][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        tree<int> g(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            g.add(x, y);
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        g.dfs(0);
        g.build_lca();
        vector<long long> ans(n + 1);
        for (int to : adj[0]) {
            ans[0] += 1LL * g.sz[to] * (g.sz[to] - 1) / 2;
        }
        int x = 1, y = 0;
        int ch = 1;
        while (g.pv[ch] != 0) {
            ch = g.pv[ch];
        }
        for (int i = 2; i < n; i++) {
            if (g.anc(i, x) || g.anc(i, y)) {
                continue;
            }
            if (y == 0) {
                int lca = g.lca(x, i);
                if (lca != x) {
                    if (g.lca(x, i) != 0) {
                        ans[i] = 1LL * g.sz[x] * (g.sz[0] - g.sz[ch]);
                        break;
                    }
                    y = i;
                    ans[i] = 1LL * g.sz[x] * (g.sz[0] - g.sz[ch] - g.sz[y]);
                } else {
                    ans[i] = 1LL * (g.sz[x] - g.sz[i]) * (g.sz[0] - g.sz[ch]);
                    x = i;
                }
            } else {
                int lx = g.lca(x, i), ly = g.lca(y, i);
                if (lx == 0 && ly == y) {
                    ans[i] = 1LL * g.sz[x] * (g.sz[y] - g.sz[i]);
                    y = i;
                } else if (ly == 0 && lx == x) {
                    ans[i] = 1LL * (g.sz[x] - g.sz[i]) * g.sz[y];
                    x = i;
                } else {
                    ans[i] = 1LL * g.sz[x] * g.sz[y];
                    break;
                }
            }
        }
        int mdeg = 1;
        for (int i = 0; i < n; i++) {
            mdeg = max(mdeg, (int)adj[i].size());
        }
        if (mdeg <= 2) {
            ans[n] = 1;
        }
        ans[1] = 1LL * n * (n - 1) / 2 - accumulate(ans.begin(), ans.end(), 0LL);
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct forest {
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
    vector<int> root;
    vector<int> sz;
    vector<int> order;
    vector<int> beg;
    vector<int> end;
    vector<T> dist;

    forest(int _n) : n(_n) {
        g = vector<vector<int>>(n);
        init();
    }

    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        root = vector<int>(n, -1);
        sz = vector<int>(n, 0);
        order = vector<int>();
        beg = vector<int>(n, -1);
        end = vector<int>(n, -1);
        dist = vector<T>(n, 0);
    }

    int add(int from, int to, T cost = 1) {
        int id = (int) edges.size();
        g[from].emplace_back(id);
        g[to].emplace_back(id);
        edges.emplace_back(from, to, cost);
        return id;
    }

    void do_dfs(int v) {
        beg[v] = (int) order.size();
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
            root[to] = (root[v] != -1 ? root[v] : to);
            dist[to] = dist[v] + e.cost;
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int) order.size();
    }

    void dfs(int v) {
        pv[v] = -1;
        pe[v] = -1;
        depth[v] = 0;
        root[v] = v;
        dist[v] = 0;
        do_dfs(v);
    }

    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                dfs(v);
            }
        }
    }

    int h;
    vector<vector<int>> p;

    inline void build_lca() {
        int max_depth = *max_element(depth.begin(), depth.end());
        h = 1;
        while ((1 << h) <= max_depth) {
            h++;
        }
        p = vector<vector<int>>(h, vector<int>(n));
        p[0] = pv;
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = (p[i - 1][j] == -1 ? -1 : p[i - 1][p[i - 1][j]]);
            }
        }
    }

    inline bool anc(int x, int y) {  // return x is y's ancestor or not
        return (beg[x] <= beg[y] && end[y] <= end[x]);
    }

    inline int go_up(int x, int up) {
        up = min(up, (1 << h) - 1);
        for (int i = h - 1; i >= 0; i--) {
            if (up & (1 << i)) {
                x = p[i][x];
                if (x == -1) {
                    break;
                }
            }
        }
        return x;
    }

    inline int lca(int x, int y) {
        if (anc(x, y)) {
            return x;
        }
        if (anc(y, x)) {
            return y;
        }
        for (int i = h - 1; i >= 0; i--) {
            if (p[i][x] != -1 && !anc(p[i][x], y)) {
                x = p[i][x];
            }
        }
        return p[0][x];
    }

    inline T distance(int x, int y) {
        return dist[x] + dist[y] - 2 * dist[lca(x, y)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forest<int> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g.add(x, y);
    }
    g.dfs_all();
    g.build_lca();
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
        }
        sort(a.begin(), a.end(), [&](int i, int j) {
            return g.beg[i] < g.beg[j];
        });
        int l = a[0];
        for (int i = 0; i < k; i++) {
            l = g.lca(l, a[i]);
        }
        if (l != a[0]) {
            a.insert(a.begin(), l);
            k++;
        }
        int cnt = 0;
        int id = -1;
        for (int i = 1; i < k; i++) {
            if (!g.anc(a[i - 1], a[i])) {
                cnt++;
                id = i;
            }
        }
        if (cnt > 1) {
            cout << "NO" << '\n';
        } else if (cnt == 0) {
            cout << "YES" << '\n';
        } else if (a[0] == g.lca(a[1], a[id])) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
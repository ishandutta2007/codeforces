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
    int tt;
    cin >> tt;
    while (tt--) {
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
        vector<vector<int>> c(n);
        for (int i = 0; i < n; i++) {
            c[g.depth[i]].emplace_back(i);
        }
        vector<int> dp(n);
        vector<int> max_depth = g.depth;
        function<void(int)> dfs = [&](int v) {
            vector<int> ch;
            for (int id : g.g[v]) {
                if (g.pe[v] == id) {
                    continue;
                }
                int to = v ^ g.edges[id].from ^ g.edges[id].to;
                dfs(to);
                dp[v] = max(dp[v], dp[to]);
                max_depth[v] = max(max_depth[v], max_depth[to]);
                ch.emplace_back(max_depth[to]);
            }
            sort(ch.rbegin(), ch.rend());
            if (ch.size() >= 2) {
                dp[v] = max(dp[v], ch[0] + ch[1] - g.depth[v] * 2);
            } else {
                dp[v] = max(dp[v], max_depth[v] - g.depth[v]);
            }
        };
        dfs(0);
        int lca = -1;
        vector<int> a(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int v : c[i]) {
                if (lca == -1) {
                    lca = v;
                } else {
                    lca = g.lca(lca, v);
                }
            }
            if (lca != -1) {
                a[i] = dp[lca];
            }
            debug(lca);
        }
        debug(lca, a);
        for (int i = 1; i <= n; i++) {
            int low = 0;
            int high = max_depth[0];
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (i + (a[mid + 1] + 1) / 2 <= mid) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            cout << high << " \n"[i == n];
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges(m);
    vector<int> ng;
    forest<int> f(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[i] = make_pair(x, y);
        if (!uf.unite(x, y)) {
            ng.emplace_back(i);
        } else {
            g[x].emplace_back(i);
            g[y].emplace_back(i);
            f.add(x, y);
        }
    }
    f.dfs_all();
    f.build_lca();
    vector<unsigned long long> hs(n);
    for (int i : ng) {
        auto [x, y] = edges[i];
        int z = f.lca(x, y);
        unsigned long long h = rng();
        debug(h);
        if (z == x || z == y) {
            if (z == y) {
                swap(x, y);
            }
            int w = f.go_up(y, f.depth[y] - f.depth[x] - 1);
            hs[w] ^= h;
            hs[y] ^= h;
        } else {
            hs[0] ^= h;
            hs[x] ^= h;
            hs[y] ^= h;
        }
    }
    function<void(int, int)> Dfs = [&](int v, int p) {
        for (int id : g[v]) {
            int to = v ^ edges[id].first ^ edges[id].second;
            if (to == p) {
                continue;
            }
            hs[to] ^= hs[v];
            Dfs(to, v);
        }
    };
    Dfs(0, -1);
    string ans(n, '1');
    for (int i = 0; i < n; i++) {
        if (hs[i]) {
            ans[i] = '0';
        }
    }
    cout << ans << '\n';
    return 0;
}
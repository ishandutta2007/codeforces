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

struct segtree {
    using T = int;
    using F = int;

    T e() {
        return 0;
    }

    F id() {
        return -1;
    }

    T op(T a, T b) {
        return a + b;
    }

    T mapping(F f, T x) {
        if (f == -1) {
            return x;
        } else {
            return f;
        }
    }

    F composition(F f, F g) {
        if (f == -1) {
            return g;
        } else {
            return f;
        }
    }

    int n;
    int size;
    int log_size;
    vector<T> node;
    vector<F> lazy;

    segtree() : segtree(0) {}
    segtree(int _n) {
        build(vector<T>(_n, e()));
    }
    segtree(const vector<T>& v) {
        build(v);
    }

    void build(const vector<T>& v) {
        n = (int) v.size();
        if (n <= 1) {
            log_size = 0;
        } else {
            log_size = 32 - __builtin_clz(n - 1);
        }
        size = 1 << log_size;
        node.resize(2 * size, e());
        lazy.resize(size, id());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            pull(i);
        }
    }

    void push(int x) {
        node[2 * x] = mapping(lazy[x], node[2 * x]);
        node[2 * x + 1] = mapping(lazy[x], node[2 * x + 1]);
        if (2 * x < size) {
            lazy[2 * x] = composition(lazy[x], lazy[2 * x]);
            lazy[2 * x + 1] = composition(lazy[x], lazy[2 * x + 1]);
        }
        lazy[x] = id();
    }

    void pull(int x) {
        node[x] = op(node[2 * x], node[2 * x + 1]);
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = v;
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    T get(int p) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        return node[p];
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        T vl = e();
        T vr = e();
        while (l < r) {
            if (l & 1) {
                vl = op(vl, node[l++]);
            }
            if (r & 1) {
                vr = op(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = mapping(f, node[p]);
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        int ll = l;
        int rr = r;
        while (l < r) {
            if (l & 1) {
                node[l] = mapping(f, node[l]);
                if (l < size) {
                    lazy[l] = composition(f, lazy[l]);
                }
                l++;
            }
            if (r & 1) {
                r--;
                node[r] = mapping(f, node[r]);
                if (l < size) {
                    lazy[r] = composition(f, lazy[r]);
                }
            }
            l >>= 1;
            r >>= 1;
        }
        l = ll;
        r = rr;
        for (int i = 1; i <= log_size; i++) {
            if (((l >> i) << i) != l) {
                pull(l >> i);
            }
            if (((r >> i) << i) != r) {
                pull((r - 1) >> i);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forest<int> g(n);
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        g.add(x, y);
        edges[z].emplace_back(x, y);
    }
    g.dfs_all();
    g.build_lca();
    vector<int> a(n);
    segtree seg(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (edges[i].empty()) {
            continue;
        }
        vector<int> vs;
        for (auto [x, y] : edges[i]) {
            if (g.depth[x] > g.depth[y]) {
                swap(x, y);
            }
            vs.emplace_back(y);
        }
        vs.emplace_back(0);
        sort(vs.begin(), vs.end(), [&](int x, int y) {
            return g.beg[x] > g.beg[y];
        });
        seg.apply(0, n, 0);
        for (int v : vs) {
            a[v] = g.sz[v] - seg.get(g.beg[v], g.end[v]);
            seg.apply(g.beg[v], g.end[v], 0);
            seg.set(g.beg[v], g.sz[v]);
            debug(i, v, a[v]);
        }
        reverse(vs.begin(), vs.end());
        vector<int> s;
        for (int v : vs) {
            while (!s.empty() && !g.anc(s.back(), v)) {
                s.pop_back();
            }
            if (!s.empty()) {
                ans += 1LL * a[s.back()] * a[v];
            }
            s.emplace_back(v);
        }
    }
    cout << ans << '\n';
    return 0;
}
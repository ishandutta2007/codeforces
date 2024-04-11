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

    inline int go_up(int x, int up) {
        up = min(up, (1 << h) - 1);
        for (int j = h - 1; j >= 0; j--) {
            if (up & (1 << j)) {
                x = p[x][j];
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
        for (int j = h - 1; j >= 0; j--) {
            if (p[x][j] != -1 && !anc(p[x][j], y)) {
                x = p[x][j];
            }
        }
        return p[x][0];
    }

    vector<int> head;

    void build_hld(int root = 0) {
        dfs(root);
        for (int i = 0; i < n; i++) {
            if (g[i].empty()) {
                continue;
            }
            int best = -1, bid = 0;
            for (int j = 0; j < (int) g[i].size(); j++) {
                int id = g[i][j];
                int v = edges[id].from ^ edges[id].to ^ i;
                if (pv[v] != i) {
                    continue;
                }
                if (sz[v] > best) {
                    best = sz[v];
                    bid = j;
                }
            }
            swap(g[i][0], g[i][bid]);
        }
        init();
        dfs(root);
        build_lca();
        head.resize(n);
        for (int i = 0; i < n; i++) {
            head[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            int x = order[i];
            int y = order[i + 1];
            if (pv[y] == x) {
                head[y] = head[x];
            }
        }
    }

    void apply(int x, int y, bool with_lca, function<void(int, int, bool)> f) {
        int z = lca(x, y);
        int v = x;
        while (v != z) {
            if (depth[head[v]] <= depth[z]) {
                f(beg[z] + 1, beg[v], true);
                break;
            }
            f(beg[head[v]], beg[v], true);
            v = pv[head[v]];
        }
        if (with_lca) {
            f(beg[z], beg[z], false);
        }
        v = y;
        vector<int> visited;
        while (v != z) {
            if (depth[head[v]] <= depth[z]) {
                f(beg[z] + 1, beg[v], false);
                break;
            }
            visited.emplace_back(v);
            v = pv[head[v]];
        }
        for (int i = (int) visited.size() - 1; i >= 0; i--) {
            v = visited[i];
            f(beg[head[v]], beg[v], false);
        }
    }
};

struct segtree {
    using T = long long;

    int n;
    vector<T> node;

    T e() {
        return 0LL;
    }

    T op(T x, T y) {
        return x + y;
    }

    segtree() : segtree(0) {}
    segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
    }
    segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void update(int k, T v) {
        k += n;
        node[k] = v;  // update
        // node[k] += v;  // add
        while (k > 1) {
            k /= 2;
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (r <= x || y <= l) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return node[x + n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    tree<int> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g.add(x, y);
    }
    g.build_hld();
    segtree seg(n);
    for (int i = 0; i < n; i++) {
        seg.update(g.beg[i], a[i]);
    }
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        x--;
        if (op == 1) {
            a[x] = abs(y);
            seg.update(g.beg[x], a[x]);
        } else {
            y--;
            long long res = 0;
            function<void(int, int, bool)> f = [&](int xx, int yy, bool) {
                res += seg.get(min(xx, yy), max(xx, yy) + 1);
            };
            g.apply(x, y, true, f);
            res *= 2;
            res -= a[x] + a[y];
            cout << res << '\n';
        }
    }
    return 0;
}
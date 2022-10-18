#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = pair<int, int>;
    using F = int;

    T e() {
        return make_pair((int) -2e9, -1);
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return max(a, b);
    }

    T mapping(F f, T x) {
        x.first += f;
        return x;
    }

    F composition(F f, F g) {
        return f + g;
    }

    int n;
    vector<T> node;
    vector<F> lazy;

    segtree() : segtree(0) {}
    segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
    }
    segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[i * 2], node[i * 2 + 1]);
        }
    }

    void eval(int k) {
        node[2 * k] = mapping(lazy[k], node[2 * k]);
        node[2 * k + 1] = mapping(lazy[k], node[2 * k + 1]);
        if (2 * k < n) {
            lazy[2 * k] = composition(lazy[k], lazy[2 * k]);
            lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
        }
        lazy[k] = id();
    }

    void update(int x, int y, F v, int k, int l, int r) {
        if (y <= l || r <= x) {
            return;
        }
        if (x <= l && r <= y) {
            node[k] = mapping(v, node[k]);
            if (k < n) {
                lazy[k] = composition(v, lazy[k]);
            }
        } else {
            eval(k);
            update(x, y, v, 2 * k, l, (l + r) / 2);
            update(x, y, v, 2 * k + 1, (l + r) / 2, r);
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (y <= l || r <= x) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        eval(k);
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    void update(int x, int y, F v) {
        update(x, y, v, 1, 0, n);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return get(x, x + 1, 1, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    {
        int z = 0;
        auto dfs = [&](auto &&self, int v, int p) -> void {
            int leaf = 1;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                leaf = 0;
                self(self, to, v);
            }
            z += leaf;
        };
        dfs(dfs, 0, -1);
        if (z <= k) {
            long long ans = 0;
            for (int i = z; i <= k; i++) {
                ans = max(ans, 1LL * i * (n - i));
            }
            cout << ans << '\n';
            return 0;
        }
    }
    int z = 0;
    vector<pair<int, int>> ss(n);
    for (int i = 0; i < n; i++) {
        ss[i].second = i;
    }
    segtree seg = segtree(ss);
    vector<int> order, beg(n), end(n);
    vector<int> pv(n);
    vector<int> l(n);
    auto dfs = [&](auto &&self, int v, int p) -> void {
        beg[v] = (int) order.size();
        order.emplace_back(v);
        pv[v] = p;
        int leaf = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            leaf = 0;
            self(self, to, v);
        }
        if (leaf) {
            l[v] = 1;
        }
        end[v] = (int) order.size();
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        seg.update(beg[i], end[i], 1);
    }
    for (int i = 0; i < n; i++) {
        if (!l[i]) {
            seg.update(beg[i], beg[i] + 1, (int) -1e9);
        }
    }
    vector<int> c(n);
    for (int i = 0; i < k; i++) {
        auto p = seg.get(0, n);
        debug(p);
        z += p.first;
        int v = order[p.second];
        while (v != -1 && c[v] == 0) {
            c[v] = 1;
            seg.update(beg[v], end[v], -1);
            v = pv[v];
        }
    }
    long long ans = (long long) 1e18;
    debug(z);
    for (int i = 0; i <= n - z; i++) {
        ans = min(ans, 1LL * (k - i) * (n - i - k));
    }
    cout << ans << '\n';
    return 0;
}
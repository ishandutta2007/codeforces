#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> q;
    vector<int> pre;
    vector<int> nxt;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        q = p;
        sz.assign(n, 1);
        pre.assign(n, -1);
        nxt.assign(n, -1);
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
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        pre[x] = q[y];
        nxt[q[y]] = x;
        p[x] = y;
        q[y] = q[x];
        sz[y] += sz[x];
        return true;
    }
    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

template <class T>
struct segtree {
    int n;
    T ie = -1;
    vector<T> node;
    function<T(T, T)> f = [&](T a, T b) { return max(a, b); };

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(_n, ie)) {}
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, ie);
        for (int i = 0; i < (int)v.size(); i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int x, T v) {
        x += n - 1;
        node[x] = v;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T get(int a, int b, int x, int l, int r) {
        if (r <= a || b <= l) {
            return ie;
        }
        if (a <= l && r <= b) {
            return node[x];
        }
        T vl = get(a, b, 2 * x + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * x + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    T get(int a) {
        return node[a + n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
        e[i].first--, e[i].second--;
    }
    vector<int> del(m);
    vector<pair<int, int>> t(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i].first >> t[i].second;
        t[i].first--, t[i].second--;
        if (t[i].first == 1) {
            del[t[i].second] = 1;
        }
    }
    dsu uf(n);
    for (int i = 0; i < m; i++) {
        if (!del[i]) {
            uf.unite(e[i].first, e[i].second);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (t[i].first == 1) {
            if (del[t[i].second]) {
                uf.unite(e[t[i].second].first, e[t[i].second].second);
            }
            t[i].first = -1;
        } else {
            int v = uf.get(t[i].second);
            t[i] = make_pair(v, uf.q[v]);
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (uf.get(i) == i) {
            int v = i;
            while (v != -1) {
                a.emplace_back(v);
                v = uf.nxt[v];
            }
        }
    }
    debug(a);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n + 1, -1);
    for (int i = 0; i < n; i++) {
        b[a[i]] = i;
        c[i] = p[a[i]];
        d[c[i]] = i;
    }
    segtree<int> st(c);
    for (int i = 0; i < q; i++) {
        if (t[i].first == -1) {
            continue;
        }
        int l = b[t[i].first], r = b[t[i].second];
        int res = st.get(l, r + 1);
        cout << res << '\n';
        if (res) {
            st.update(d[res], 0);
        }
    }
    return 0;
}
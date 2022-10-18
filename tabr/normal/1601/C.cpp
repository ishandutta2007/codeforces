#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }

    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

struct segtree {
    using T = int;
    using F = int;

    T e() {
        return (int) 2e9;
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return min(a, b);
    }

    T mapping(F f, T x) {
        return f + x;
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> c(n + m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[i] = a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            c[i + n] = b[i];
        }
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());
        for (int i = 0; i < n; i++) {
            a[i] = (int) (lower_bound(c.begin(), c.end(), a[i]) - c.begin());
        }
        for (int i = 0; i < m; i++) {
            b[i] = (int) (lower_bound(c.begin(), c.end(), b[i]) - c.begin());
        }
        sort(b.begin(), b.end());
        int z = (int) c.size() + 10;
        fenwick<int> ft(z);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ft.add(a[i], 1);
            ans += ft.get(a[i] + 1, z - 1);
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) { return a[x] < a[y]; });
        vector<int> s(n + 1);
        iota(s.begin(), s.end(), 0);
        segtree seg(s);
        for (int i = 0, j = 0, k = 0; i < m; i++) {
            while (j < n && a[order[j]] <= b[i]) {
                seg.update(order[j] + 1, n + 1, -1);
                j++;
            }
            while (k < n && a[order[k]] < b[i]) {
                seg.update(0, order[k], 1);
                k++;
            }
            ans += seg.node[1];
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = int;
    using F = int;

    T e() {
        return (int) 1e9;
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
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n, e());
        lazy.resize(n, id());
    }
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int) v.size() - 1));
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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        l--, r--;
        edges.emplace_back(w, l, r);
    }
    sort(edges.begin(), edges.end());
    int ans = (int) 1e9;
    segtree seg(vector<int>(m - 1));
    int j = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = edges[i];
        while (j < n && seg.get(0, m - 1) == 0) {
            auto [ww, ll, rr] = edges[j];
            c = ww;
            seg.update(ll, rr, 1);
            j++;
        }
        if (seg.get(0, m - 1) == 0) {
            break;
        }
        ans = min(ans, c - w);
        seg.update(l, r, -1);
    }
    cout << ans << '\n';
    return 0;
}
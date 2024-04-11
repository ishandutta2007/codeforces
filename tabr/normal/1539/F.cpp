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
        return T{(int) -2e9, (int) 2e9};
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return T{max(a.first, b.first), min(a.second, b.second)};
    }

    T mapping(F f, T x) {
        return T{f + x.first, f + x.second};
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]].emplace_back(i);
    }
    vector<int> ans(n);
    vector<pair<int, int>> d(n + 1);
    for (int i = 0; i <= n; i++) {
        d[i] = {-i, -i};
    }
    segtree seg(d);
    auto solve = [&](int i) -> int {
        return seg.get(i + 1, n + 1).first - seg.get(0, i + 1).second;
    };
    for (int k = 0; k < n; k++) {
        for (int i : b[k]) {
            seg.update(i + 1, n + 1, 2);
        }
        for (int i : b[k]) {
            int t = solve(i);
            ans[i] = (t - 1) / 2;
        }
    }
    seg = segtree(d);
    for (int k = n - 1; k >= 0; k--) {
        for (int i : b[k]) {
            seg.update(i + 1, n + 1, 2);
        }
        for (int i : b[k]) {
            int t = solve(i);
            ans[i] = max(ans[i], t / 2);
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
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
        return (int) -1e9;
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return max(a, b);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= d) {
            if (y <= d) {
                ans++;
            } else {
                a.emplace_back(x, y);
            }
        }
    }
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        if (x.second == y.second) {
            return x.first < y.first;
        } else {
            return x.second < y.second;
        }
    });
    n = (int) a.size();
    a.insert(a.begin(), make_pair(0, d));
    vector<int> b(n + 1), c(n + 1);
    for (int i = 0; i <= n; i++) {
        tie(b[i], c[i]) = a[i];
    }
    vector<int> dp(n + 1);
    vector<int> order(n + 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) { return b[x] < b[y]; });
    vector<int> s(n + 1);
    segtree seg(s);
    fenwick<int> ft(n + 1);
    for (int i = 0; i <= n; i++) {
        ft.add(i, 1);
        seg.update(i, i + 1, -i - 1);
    }
    int it = 0;
    debug(b);
    debug(c);
    for (int j = 1; j <= n; j++) {
        while (it <= n && b[order[it]] < c[j]) {
            ft.add(order[it], -1);
            seg.update(order[it], n + 1, 1);
            it++;
        }
        int i = (int) (upper_bound(c.begin(), c.begin() + j, b[j]) - c.begin());
        dp[j] = seg.get(0, i) + ft.get(j - 1) + 1;
        seg.update(j, j + 1, dp[j]);
        // debug(i, j, dp[j]);
        // for (int k = 0; k <= n; k++) {
        //     debug(seg.get(k), ft.get(k), dp[k]);
        // }
    }
    ans += *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
    return 0;
}
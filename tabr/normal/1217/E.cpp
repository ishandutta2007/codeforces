#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int inf = INT32_MAX;

struct segtree {
    using T = pair<int, int>;

    int n;
    vector<T> node;

    T e = {inf, inf};

    function<T(T, T)> f = [&](T a, T b) {
        for (int i : {b.first, b.second}) {
            a.second = min(a.second, i);
            if (a.first > a.second) {
                swap(a.first, a.second);
            }
        }
        return a;
    };

    segtree() : segtree(0) {}
    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n - 1, e);
    }
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, e);
        for (int i = 0; i < (int)v.size(); i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int x, T v) {
        x += n - 1;
        node[x] = v;  // update
        // node[x] += v;  // add
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T get(int a, int b, int x, int l, int r) {
        if (r <= a || b <= l) {
            return e;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<segtree> st(9, segtree(n));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int b = a[i];
        for (int k = 0; k < 9; k++) {
            if (b % 10) {
                st[k].update(i, {a[i], inf});
            }
            b /= 10;
        }
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            int b = x;
            for (int k = 0; k < 9; k++) {
                if (b % 10) {
                    st[k].update(i, {x, inf});
                } else {
                    st[k].update(i, {inf, inf});
                }
                b /= 10;
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int ans = inf;
            for (int k = 0; k < 9; k++) {
                auto p = st[k].get(l, r + 1);
                if (p.second != inf) {
                    ans = min(ans, p.first + p.second);
                }
            }
            cout << (ans == inf ? -1 : ans) << '\n';
        }
    }
    return 0;
}
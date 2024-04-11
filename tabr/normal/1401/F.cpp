#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct segtree {
    int n;
    int t = 0;
    T def = 0;
    vector<T> node;
    function<T(T, T)> f = [&](T a, T b) { return a + b; };

    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n - 1, def);
    }
    segtree(vector<T> a) {
        n = 1 << (32 - __builtin_clz((int)a.size() - 1));
        node.resize(2 * n - 1, def);
        for (int i = 0; i < a.size(); i++) {
            node[i + n - 1] = a[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int k, T v) {
        k += n - 1;
        node[k] = v;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = f(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    T get(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return def;
        }
        if (a <= l && r <= b) {
            return node[k];
        }
        int c = (r - l) / 2;
        T vl, vr;
        if (t & c) {
            vl = get(max(l, a - c), min((l + r) / 2, b - c), 2 * k + 1, l, (l + r) / 2);
            vr = get(max((l + r) / 2, a + c), min(r, b + c), 2 * k + 2, (l + r) / 2, r);
        } else {
            vl = get(max(l, a), min((l + r) / 2, b), 2 * k + 1, l, (l + r) / 2);
            vr = get(max((l + r) / 2, a), min(r, b), 2 * k + 2, (l + r) / 2, r);
        }
        return f(vl, vr);
    }
    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = 1 << n;
    int q;
    cin >> q;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    segtree<ll> st(a);
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            x--;
            ll b;
            cin >> b;
            st.update(x ^ st.t, b);
        } else if (c == 2) {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                st.t ^= 1 << i;
            }
        } else if (c == 3) {
            int k;
            cin >> k;
            st.t ^= 1 << k;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.get(l, r) << '\n';
        }
    }
    return 0;
}
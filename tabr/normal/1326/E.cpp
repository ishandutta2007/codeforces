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
    T def = 0;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };  // node-node
    function<T(T, T)> g = [&](T a, T b) { return a + b; };      // node-lazy if add a + b

    segtree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
    }

    inline void eval(int k, int l, int r) {
        if (!flag[k]) return;
        node[k] = g(node[k], lazy[k]);
        // node[k] = g(node[k], lazy[k]) * (r - l);  // sum
        if (r - l > 1) {
            lazy[k * 2 + 1] = g(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = g(lazy[k * 2 + 2], lazy[k]);
            flag[k * 2 + 1] = flag[k * 2 + 2] = true;
        }
        lazy[k] = 0;
        flag[k] = false;
    }
    inline void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = g(lazy[k], v);
            flag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, v, 2 * k + 1, l, (l + r) / 2);
            update(a, b, v, 2 * k + 2, (l + r) / 2, r);
            node[k] = f(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    inline T get(int a, int b, int k, int l, int r) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return def;
        if (a <= l && r <= b) return node[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    inline void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }
    inline T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
    inline T get(int a) {
        return get(a, a + 1, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), q(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        r[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    segtree<ll> st(n);
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        while (true) {
            st.update(0, r[ans] + 1, -1);
            if (st.get(0, n) >= 0) {
                ans--;
            } else {
                st.update(0, r[ans] + 1, 1);
                break;
            }
        }
        cout << ans + 1 << " ";
        st.update(0, q[i] + 1, 1);
    }
    cout << endl;
    return 0;
}
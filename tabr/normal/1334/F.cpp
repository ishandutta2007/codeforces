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
    T def = 5e18;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };  // node-node
    function<T(T, T)> g = [&](T a, T b) { return (a + b); };    // node-lazy if add a + b

    segtree(vector<T> a) {
        n = 1;
        while (n < a.size()) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
        for (int i = 0; i < a.size(); i++) node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--) node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);
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
    inline int find_first(int a, int b, function<bool(T)> fn, int k, int l, int r) {
        eval(k, l, r);
        if (!fn(node[k]) || b <= l || r <= a) return b;
        if (k >= n - 1) return k - n + 1;
        int res = find_first(a, b, fn, 2 * k + 1, l, (l + r) / 2);
        if (res != b) return res;
        return find_first(a, b, fn, 2 * k + 2, (l + r) / 2, r);
    }
    inline int find_first(int a, int b, function<bool(T)> fn) {
        return find_first(a, b, fn, 0, 0, n);
    }
    inline int find_last(int a, int b, function<bool(T)> fn, int k, int l, int r) {
        eval(k, l, r);
        if (!fn(node[k]) || b <= l || r <= a) return a - 1;
        if (k >= n - 1) return k - n + 1;
        int res = find_last(a, b, fn, 2 * k + 2, (l + r) / 2, r);
        if (res != a - 1) return res;
        return find_last(a, b, fn, 2 * k + 1, l, (l + r) / 2);
    }
    inline int find_last(int a, int b, function<bool(T)> fn) {
        return find_last(a, b, fn, 0, 0, n);
    }
};

template <class T>
string to_string(segtree<T> st) {
    vector<T> res(st.n);
    for (int i = 0; i < st.n; i++) {
        res[i] = st.get(i);
    }
    return to_string(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int m;
    cin >> m;
    vector<int> b(m), pos(n + 2);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        pos[b[i]] = i + 1;
    }
    for (int i = 1; i <= n + 1; i++) {
        pos[i] = max(pos[i], pos[i - 1]);
    }
    vector<ll> x(m + 1, 1e18);
    x[0] = 0;
    segtree<ll> st(x);
    for (int i = 0; i < n; i++) {
        int c = a[i];
        if (p[i] < 0) {
            if (pos[c] != pos[c - 1]) {
                ll t = st.get(pos[c] - 1);
                st.update(0, m + 1, p[i]);
                ll u = st.get(pos[c]);
                if (u > t) {
                    st.update(pos[c], pos[c] + 1, t - u);
                }
            } else {
                st.update(0, m + 1, p[i]);
            }
        } else if (p[i] >= 0) {
            if (pos[c] != pos[c - 1]) {
                ll t = st.get(pos[c] - 1), u = st.get(pos[c]);
                if (u > t) {
                    st.update(pos[c], pos[c] + 1, t - u);
                }
                st.update(0, pos[c], p[i]);
            } else {
                st.update(0, pos[c] + 1, p[i]);
            }
        }
        debug(st);
    }
    ll ans = st.get(m);
    if (ans > 1e15) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << ans << '\n';
    }
    debug(pos);
    return 0;
}
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
    T def = 1e18;
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
    inline int find_first(int a, int b, function<bool(T)> f, int k, int l, int r) {
        eval(k, l, r);
        if (!f(node[k]) || b <= l || r <= a) return b;
        if (k >= n - 1) return k - n + 1;
        int res = find_first(a, b, f, 2 * k + 1, l, (l + r) / 2);
        if (res != b) return res;
        return find_first(a, b, f, 2 * k + 2, (l + r) / 2, r);
    }
    inline int find_first(int a, int b, function<bool(T)> f) {
        return find_first(a, b, f, 0, 0, n);
    }
    inline int find_last(int a, int b, function<bool(T)> f, int k, int l, int r) {
        eval(k, l, r);
        if (!f(node[k]) || b <= l || r <= a) return a - 1;
        if (k >= n - 1) return k - n + 1;
        int res = find_last(a, b, f, 2 * k + 2, (l + r) / 2, r);
        if (res != a - 1) return res;
        return find_last(a, b, f, 2 * k + 1, l, (l + r) / 2);
    }
    inline int find_last(int a, int b, function<bool(T)> f) {
        return find_last(a, b, f, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    segtree<ll> st(p);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        /*
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (st.get(mid, st.n) == 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        */
        int pos = st.find_last(0, n, [&](ll a) { return a == 0; });
        st.update(pos, pos + 1, 1e17);
        st.update(pos + 1, n, -i - 1);
        ans[pos] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
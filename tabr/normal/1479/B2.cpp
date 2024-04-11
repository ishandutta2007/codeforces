#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct segtree {
    int n;
    T ie = 1e9;
    vector<T> node;
    vector<T> lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };  // node-node
    function<T(T, T)> g = [&](T a, T b) { return a + b; };      // node-lazy if add a + b

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(_n, ie)) {}
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, ie);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1);
        for (int i = 0; i < (int)v.size(); i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    void eval(int x, int l, int r) {
        if (!flag[x]) {
            return;
        }
        node[x] = g(node[x], lazy[x]);
        // node[x] = g(node[x], lazy[x]) * (r - l);  // RSQ
        if (r - l > 1) {
            lazy[x * 2 + 1] = g(lazy[x * 2 + 1], lazy[x]);
            lazy[x * 2 + 2] = g(lazy[x * 2 + 2], lazy[x]);
            flag[x * 2 + 1] = flag[x * 2 + 2] = true;
        }
        lazy[x] = 0;
        flag[x] = false;
    }

    void update(int a, int b, T v, int x, int l, int r) {
        eval(x, l, r);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[x] = g(lazy[x], v);
            flag[x] = true;
            eval(x, l, r);
        } else {
            update(a, b, v, 2 * x + 1, l, (l + r) / 2);
            update(a, b, v, 2 * x + 2, (l + r) / 2, r);
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T get(int a, int b, int x, int l, int r) {
        eval(x, l, r);
        if (b <= l || r <= a) {
            return ie;
        }
        if (a <= l && r <= b) {
            return node[x];
        }
        T vl = get(a, b, 2 * x + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * x + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }

    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    T get(int a) {
        return get(a, a + 1, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    segtree<int> st(vector<int>(n + 1, 1e8));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int b = n;
    st.update(n, n + 1, -1e8);
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            continue;
        }
        int v = 1e9;
        if (a[i]) {
            v = min(v, st.get(0, a[i]));
        }
        v = min(v, st.get(a[i] + 1, n + 1));
        v++;
        v = min(v, st.get(a[i], a[i] + 1));
        st.update(0, n + 1, 1);
        int u = st.get(b, b + 1);
        if (v < u) {
            st.update(b, b + 1, v - u);
        }
        b = a[i];
        debug(st.node[0]);
    }
    cout << st.get(0, n + 1) << '\n';
    return 0;
}
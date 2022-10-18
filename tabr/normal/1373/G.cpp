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
    T def = -1e9;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) { return max(a, b); };  // node-node
    function<T(T, T)> g = [&](T a, T b) { return a + b; };      // node-lazy if add a + b

    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
    }
    segtree(vector<T> a) {
        n = 1 << (32 - __builtin_clz((int)a.size() - 1));
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
        for (int i = 0; i < (int)a.size(); i++) {
            node[i + n - 1] = a[i];
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
        // node[x] = g(node[x], lazy[x]) * (r - l);  // sum
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
            return def;
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
    int n, m, k;
    cin >> n >> k >> m;
    set<pair<int, int>> s;
    multiset<int> t;
    vector<int> a(2 * n + 2);
    iota(a.begin(), a.end(), 0);
    segtree<int> st(a);
    while (m--) {
        int x, y;
        cin >> x >> y;
        int z = y + abs(x - k);
        if (s.count({x, y})) {
            t.erase(t.find(z));
            s.erase({x, y});
            st.update(0, z + 1, -1);
        } else {
            s.emplace(x, y);
            t.emplace(z);
            st.update(0, z + 1, 1);
        }
        if (s.empty()) {
            cout << 0 << '\n';
            continue;
        }
        int val = st.get(0, *t.rbegin() + 1);
        cout << max(0, val - n - 1) << '\n';
    }
    return 0;
}
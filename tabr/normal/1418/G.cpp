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
    T e = make_pair(0, 1);
    vector<T> node;
    vector<T> lazy;
    vector<bool> flag;
    function<T(T, T)> f = [&](T a, T b) {
        if (a.first == b.first) {
            return make_pair(a.first, a.second + b.second);
        }
        return max(a, b);
    };  // node-node
    function<T(T, T)> g = [&](T a, T b) {
        a.first += b.first;
        return a;
    };  // node-lazy if add a + b

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(n, e)) {}
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, e);
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
        lazy[x] = {};
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
            return e;
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<pair<int, int>> tmp(n, {n, 1});
    segtree<pair<int, int>> st(tmp);
    long long ans = 0;
    vector<vector<int>> pos(n, vector<int>(1, -1));
    debug(st.get(0, n));
    for (int i = 0; i < n; i++) {
        st.update(pos[a[i]].back() + 1, i + 1, {-1, 0});
        int sz = (int)pos[a[i]].size();
        if (sz >= 3) {
            st.update(pos[a[i]][sz - 3] + 1, pos[a[i]][sz - 2] + 1, {1, 0});
        }
        if (sz >= 4) {
            st.update(pos[a[i]][sz - 4] + 1, pos[a[i]][sz - 3] + 1, {-1, 0});
        }
        pos[a[i]].emplace_back(i);
        debug(st.get(0, i + 1));
        if (st.get(0, i + 1).first == n) {
            ans += st.get(0, i + 1).second;
        }
    }
    cout << ans << '\n';
    return 0;
}
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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    vector<int> s(n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        a[i][2]--;
        s[i] = a[i][0];
        s[i + n] = a[i][1];
    }
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    int m = s.size();
    vector<vector<vector<int>>> c(m, vector<vector<int>>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = lower_bound(s.begin(), s.end(), a[i][j]) - s.begin();
        }
        c[a[i][1]][a[i][2]].emplace_back(a[i][0]);
    }
    vector<segtree<int>> st(2, segtree<int>(m + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k : c[i][j]) {
                st[j].update(0, k + 1, 1);
            }
        }
        int v = max(st[0].node[0], st[1].node[0]);
        st[0].update(i + 1, i + 2, v);
        st[1].update(i + 1, i + 2, v);
    }
    cout << max(st[0].node[0], st[1].node[0]) << '\n';
    return 0;
}
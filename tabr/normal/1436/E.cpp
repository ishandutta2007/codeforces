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
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(_n, ie)) {}
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, ie);
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
            return ie;
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> b(n + 3);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i]) {
            b[0] = true;
        }
    }
    vector<int> lst(n + 1, -1);
    segtree<int> st(lst);
    for (int i = 0; i < n; i++) {
        st.update(a[i], i);
        if (a[i] == 0) {
            b[1] = true;
            continue;
        }
        if (st.get(0, a[i]) > lst[a[i]]) {
            b[a[i]] = true;
        }
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (st.get(0, i) > lst[i]) {
            b[i] = true;
        }
    }
    for (int i = 0; i < n + 3; i++) {
        if (!b[i]) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}
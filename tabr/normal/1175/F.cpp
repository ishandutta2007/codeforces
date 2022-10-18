#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = int;

    int n;
    vector<T> node;

    T e = (int)1e9;

    function<T(T, T)> f = [&](T a, T b) {
        return min(a, b);
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    segtree st(vector<int>(n, -1));
    int lst = 0;
    for (int i = 0; i < n; i++) {
        lst = max(lst, st.get(a[i]) + 1);
        st.update(a[i], i);
        for (int j = a[i]; j <= i - lst;) {
            int k = st.get(0, j + 1);
            if (k == i - j) {
                ans++;
                j++;
            } else {
                j = i - k;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
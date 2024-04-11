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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> x(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            x[a[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; i++) {
            reverse(x[i].begin(), x[i].end());
        }
        segtree st(a);
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (x[b[i]].empty()) {
                ans = "NO";
                break;
            }
            int c = x[b[i]].back();
            x[b[i]].pop_back();
            if (c != 0 && st.get(0, c) < b[i]) {
                ans = "NO";
                break;
            }
            st.update(c, n + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
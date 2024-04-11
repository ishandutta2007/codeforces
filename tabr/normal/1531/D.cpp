#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = array<int, 3>;

    int n;
    vector<T> node;

    T e() {
        return T{-1, -1, -1};
    }

    T op(T x, T y) {
        if (x == e()) {
            return y;
        }
        if (y == e()) {
            return x;
        }
        array<int, 3> z;
        if (y[2] != -1) {
            z[2] = y[2];
        } else {
            z[2] = x[2];
        }
        {
            int s = x[0];
            int t = x[2];
            if (t == -1) {
                t = 0;
            }
            if (y[t] != -1) {
                s = y[t];
            }
            z[0] = s;
        }
        {
            int s = x[1];
            int t = x[2];
            if (t == -1) {
                t = 1;
            }
            if (y[t] != -1) {
                s = y[t];
            }
            z[1] = s;
        }
        return z;
    }

    segtree() : segtree(0) {}
    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n, e());
    }
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        node.resize(2 * n, e());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void update(int k, T v) {
        k += n;
        node[k] = v;  // update
        // node[k] += v;  // add
        while (k > 1) {
            k /= 2;
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (r <= x || y <= l) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return node[x + n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> mp = {"lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"};
    vector<int> a(n + 1);
    a[0] = 6;
    segtree seg(n + 1);
    seg.update(0, array<int, 3>{-1, 6, -1});
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < 9; j++) {
            if (t == mp[j]) {
                a[i] = j;
            }
        }
        if (a[i] >= 2) {
            seg.update(i, array<int, 3>{-1, a[i], -1});
        } else {
            seg.update(i, array<int, 3>{-1, -1, a[i]});
        }
    }
    cout << mp[seg.get(0, n + 1)[1]] << '\n';
    int tt;
    cin >> tt;
    while (tt--) {
        int id;
        string t;
        cin >> id >> t;
        int b = -1;
        for (int j = 0; j < 9; j++) {
            if (t == mp[j]) {
                b = j;
            }
        }
        if (b >= 2) {
            seg.update(id, array<int, 3>{-1, b, -1});
        } else {
            seg.update(id, array<int, 3>{-1, -1, b});
        }
        cout << mp[seg.get(0, n + 1)[1]] << '\n';
    }
    return 0;
}
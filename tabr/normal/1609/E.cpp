#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    struct T {
        int a;
        int b;
        int c;
        int ab;
        int bc;
        int abc;
    };

    int n;
    vector<T> node;

    T e() {
        T e;
        e.a = e.b = e.c = e.ab = e.bc = e.abc = 0;
        return e;
    }

    T op(T x, T y) {
        T res;
        res.a = res.b = res.c = res.ab = res.bc = res.abc = (int) 1e9;
        res.a = min(res.a, x.a + y.a);
        res.b = min(res.b, x.b + y.b);
        res.c = min(res.c, x.c + y.c);
        res.ab = min(res.ab, x.a + y.b);
        res.ab = min(res.ab, x.ab + y.b);
        res.ab = min(res.ab, x.a + y.ab);
        res.bc = min(res.bc, x.b + y.c);
        res.bc = min(res.bc, x.bc + y.c);
        res.bc = min(res.bc, x.b + y.bc);
        res.abc = min(res.abc, x.a + y.bc);
        res.abc = min(res.abc, x.ab + y.c);
        res.abc = min(res.abc, x.a + y.abc);
        res.abc = min(res.abc, x.ab + y.bc);
        res.abc = min(res.abc, x.abc + y.c);
        return res;
    }

    segtree() : segtree(0) {}
    segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
    }
    segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<segtree::T> z;
    z.emplace_back(segtree::T{1, 0, 0, 1, 0, 1});
    z.emplace_back(segtree::T{0, 1, 0, 1, 1, 1});
    z.emplace_back(segtree::T{0, 0, 1, 0, 1, 1});
    vector<segtree::T> se;
    for (int i = 0; i < n; i++) {
        se.emplace_back(z[s[i] - 'a']);
    }
    segtree seg(se);
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        seg.update(p, z[c - 'a']);
        segtree::T r = seg.node[1];
        debug(r.a, r.b, r.c, r.ab, r.bc, r.abc);
        cout << min({r.a, r.b, r.c, r.ab, r.bc, r.abc}) << '\n';
    }
    return 0;
}
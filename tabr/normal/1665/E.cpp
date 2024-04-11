#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const int B = 50;

struct segtree {
    using T = array<int, B>;
    int n;
    int size;
    vector<T> node;

    T e() {
        T t;
        fill(t.begin(), t.end(), INT_MAX);
        return t;
    }

    T op(T x, T y) {
        array<int, B * 2> xy;
        for (int i = 0; i < B; i++) {
            xy[i] = x[i];
            xy[i + B] = y[i];
        }
        sort(xy.begin(), xy.end());
        T z;
        for (int i = 0; i < B; i++) {
            z[i] = xy[i];
        }
        return z;
    }

    segtree() : segtree(0) {}
    segtree(int _n) {
        build(vector<T>(_n, e()));
    }
    segtree(const vector<T> &v) {
        build(v);
    }

    void build(const vector<T> &v) {
        n = (int) v.size();
        if (n <= 1) {
            size = n;
        } else {
            size = 1 << (32 - __builtin_clz(n - 1));
        }
        node.resize(2 * size, e());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        node[p] = v;  // update
        // node[p] += v;  // add
        while (p > 1) {
            p >>= 1;
            node[p] = op(node[2 * p], node[2 * p + 1]);
        }
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        T vl = e();
        T vr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) {
                vl = op(vl, node[l++]);
            }
            if (r & 1) {
                vr = op(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

    T get(int p) {
        assert(0 <= p && p < n);
        return node[p + size];
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
        vector<array<int, B>> sdef(n);
        for (int i = 0; i < n; i++) {
            fill(sdef[i].begin(), sdef[i].end(), INT_MAX);
            cin >> sdef[i][0];
        }
        segtree seg(sdef);
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int ans = INT_MAX;
            auto c = seg.get(l, r + 1);
            for (int i = 0; i < B; i++) {
                for (int j = i + 1; j < B; j++) {
                    ans = min(ans, c[i] | c[j]);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = int;

    T e() {
        return (int) 2e9;
    }

    T op(T x, T y) {
        return min(x, y);
    }

    int n;
    int size;
    vector<T> node;

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] -= i + 1;
        }
        segtree seg(a);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] + i < 0) {
                continue;
            }
            int low = i;
            int high = n;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (seg.get(i, mid + 1) + i >= 0) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans += high - i;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = long long;
    int n;
    int size;
    vector<T> node;

    T e() {
        return (long long) -1e18;
    }

    T op(T x, T y) {
        return max(x, y);
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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        auto b = pref;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        vector<int> c(n + 1);
        for (int i = 0; i < n + 1; i++) {
            c[i] = (int) (lower_bound(b.begin(), b.end(), pref[i]) - b.begin());
        }
        segtree seg1(n + 10), seg2(n + 10);
        vector<long long> dp(n + 1, (long long) -1e18);
        vector<long long> d(n + 10, (long long) -1e18);
        dp[0] = 0;
        seg1.set(c[0], 0);
        seg2.set(c[0], 0);
        d[c[0]] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(seg1.get(c[i] + 1, n + 10) - i, seg2.get(0, c[i]) + i);
            dp[i] = max(dp[i], d[c[i]]);
            d[c[i]] = max(d[c[i]], dp[i]);
            seg1.set(c[i], max(seg1.get(c[i]), dp[i] + i));
            seg2.set(c[i], max(seg2.get(c[i]), dp[i] - i));
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
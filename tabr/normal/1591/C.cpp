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
    vector<T> node;

    T e() {
        return (long long) 1e18;
    }

    T op(T x, T y) {
        return min(x, y);
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 0) {
                a.emplace_back(x);
            } else if (x < 0) {
                b.emplace_back(-x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0;
        for (int loop = 0; loop < 2; loop++) {
            segtree seg((int) a.size() + 1);
            seg.update(0, 0);
            for (int i = 0; i < (int) a.size(); i++) {
                long long t = a[i] * 2 + seg.get(max(0, i - k + 1), i + 1);
                seg.update(i + 1, t);
            }
            ans += seg.get((int) a.size());
            swap(a, b);
        }
        if (a.empty()) {
            a.emplace_back(0);
        }
        if (b.empty()) {
            b.emplace_back(0);
        }
        ans -= max(a.back(), b.back());
        cout << ans << '\n';
    }
    return 0;
}
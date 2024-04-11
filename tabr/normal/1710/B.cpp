#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = long long;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        return max(x, y);
    }

    sparse(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) {
        if (l == r) {
            return (long long) -1e18;
        }
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> x(n);
        vector<long long> p(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> p[i];
        }
        auto y = x;
        sort(y.begin(), y.end());
        y.resize(unique(y.begin(), y.end()) - y.begin());
        int sz = (int) y.size();
        vector<long long> a(sz);
        auto z = x;
        for (int i = 0; i < n; i++) {
            z.emplace_back(x[i] - p[i]);
            z.emplace_back(x[i] + p[i]);
        }
        sort(z.begin(), z.end());
        z.resize(unique(z.begin(), z.end()) - z.begin());
        int sz2 = (int) z.size();
        vector<long long> d(sz2);
        for (int i = 0; i < n; i++) {
            d[lower_bound(z.begin(), z.end(), x[i] - p[i]) - z.begin()] += 1;
            d[lower_bound(z.begin(), z.end(), x[i]) - z.begin()] -= 2;
            d[lower_bound(z.begin(), z.end(), x[i] + p[i]) - z.begin()] += 1;
        }
        for (int i = 1; i < sz2; i++) {
            d[i] += d[i - 1];
        }
        long long sum = 0;
        vector<long long> e(sz2);
        for (int i = 0; i < sz2; i++) {
            e[i] = sum;
            if (i + 1 < sz2) {
                sum += d[i] * (z[i + 1] - z[i]);
            }
        }
        for (int i = 0; i < sz; i++) {
            a[i] = e[lower_bound(z.begin(), z.end(), y[i]) - z.begin()];
        }
        /*
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < n; j++) {
                a[i] += max(0LL, p[j] - abs(x[j] - y[i]));
            }
        }
        */
        vector<long long> b = a, c = a;
        for (int i = 0; i < sz; i++) {
            b[i] += y[i];
            c[i] -= y[i];
        }
        sparse spa(a), spb(b), spc(c);
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            int low = (int) (lower_bound(y.begin(), y.end(), x[i] - p[i] + 1) - y.begin());
            int mid = (int) (lower_bound(y.begin(), y.end(), x[i]) - y.begin());
            int high = (int) (lower_bound(y.begin(), y.end(), x[i] + p[i]) - y.begin());
            long long t = 0;
            t = max(t, spa.get(0, low));
            t = max(t, spc.get(low, mid) + x[i] - p[i]);
            t = max(t, spb.get(mid, high) - x[i] - p[i]);
            t = max(t, spa.get(high, sz));
            if (t <= m) {
                ans[i] = '1';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

namespace smin {
struct sparse {
    using T = int;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        return min(x, y);
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
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};
}  // namespace smin

namespace smax {
struct sparse {
    using T = int;
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
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};
}  // namespace smax

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
            a[i]--;
        }
        vector<int> at(n);
        for (int i = 0; i < n; i++) {
            at[a[i]] = i;
        }
        smin::sparse spmin(a);
        smax::sparse spmax(a);
        int now = 0;
        int ans = 0;
        while (now < n - 1) {
            ans++;
            debug(now);
            if (a[now] > a[now + 1]) {
                int low = now + 1;
                int high = n + 1;
                while (high - low > 1) {
                    int mid = (high + low) >> 1;
                    if (spmax.get(now, mid) == a[now]) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                int t = spmin.get(now, low);
                now = at[t];
            } else {
                int low = now + 1;
                int high = n + 1;
                while (high - low > 1) {
                    int mid = (high + low) >> 1;
                    if (spmin.get(now, mid) == a[now]) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                int t = spmax.get(now, low);
                now = at[t];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
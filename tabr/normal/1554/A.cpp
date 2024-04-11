#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    struct T {
        int mn = (int) 1e9;
        int mx = (int) -1e9;
        int id = -1;
    };
    int n, h;
    vector<vector<T>> table;
    T func(T x, T y) {
        T res;
        if (x.mn <= y.mn) {
            res = x;
        } else {
            res = y;
        }
        res.mx = max(x.mx, y.mx);
        return res;
    }

    sparse(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) {  // [from, to]
        int k = 32 - __builtin_clz(to - from + 1) - 1;
        return func(table[k][from], table[k][to - (1 << k) + 1]);
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
        }
        vector<sparse::T> ss(n);
        for (int i = 0; i < n; i++) {
            ss[i].mx = ss[i].mn = a[i];
            ss[i].id = i;
        }
        sparse sp(ss);
        long long ans = (long long) -1e18;
        auto solve = [&](auto &&self, int l, int r) -> void {
            if (r - l < 2) {
                return;
            }
            sparse::T z = sp.get(l, r - 1);
            self(self, z.id + 1, r);
            self(self, l, z.id);
            ans = max(ans, 1LL * z.mx * z.mn);
        };
        solve(solve, 0, n);
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = long long;
    int n, h;
    vector<vector<T>> table;
    T func(T x, T y) {
        return __gcd(x, y);
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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        vector<long long> b(n - 1);
        for (int i = 0; i < n - 1; i++) {
            b[i] = abs(a[i + 1] - a[i]);
        }
        sparse sp(b);
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] == 1) {
                continue;
            }
            int lo = i, hi = n - 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (sp.get(i, mid) != 1) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            ans = max(ans, lo - i + 2);
        }
        cout << ans << '\n';
    }
    return 0;
}
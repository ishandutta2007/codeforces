#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = pair<long long, int>;
    int n, h;
    vector<vector<T>> table;
    T func(T x, T y) {
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
        long long x;
        cin >> x;
        for (int i = 0; i < n; i++) {
            a[i] -= x;
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        vector<pair<long long, int>> ss(n + 1);
        for (int i = 0; i <= n; i++) {
            ss[i] = make_pair(pref[i], i);
        }
        sparse sp(ss);
        vector<int> b(n);
        b[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            b[i] = b[i + 1];
            if (pref[i] > pref[i + 2]) {
                b[i] = i + 1;
                continue;
            }
            int lo = i + 2;
            int hi = n + 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                auto p = sp.get(i + 2, mid);
                if (p.first < pref[i]) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            b[i] = min(b[i], lo);
        }
        debug(pref);
        debug(b);
        vector<int> dp(n + 2);
        dp[n + 1] = -1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            dp[i] = min(dp[i], dp[b[i] + 1] + 1);
        }
        cout << n - dp[0] << '\n';
    }
    return 0;
}
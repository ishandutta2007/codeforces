#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        long long mx = (long long) -1e18;
        vector<int> ans(m);
        for (int mask = 0; mask < (1 << n); mask++) {
            long long v = 0;
            vector<int> t(m);
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) {
                    // x - r
                    v += x[bit];
                    for (int i = 0; i < m; i++) {
                        t[i] -= a[bit][i];
                    }
                } else {
                    // r - x
                    v -= x[bit];
                    for (int i = 0; i < m; i++) {
                        t[i] += a[bit][i];
                    }
                }
            }
            vector<int> order(m);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int i, int j) {
                return t[i] < t[j];
            });
            for (int i = 0; i < m; i++) {
                v += (i + 1) * t[order[i]];
            }
            if (v > mx) {
                mx = v;
                vector<int> s(m);
                for (int i = 0; i < m; i++) {
                    ans[order[i]] = i;
                }
            }
        }
        debug(mx);
        for (int i = 0; i < m; i++) {
            cout << ans[i] + 1 << " \n"[i == m - 1];
        }
    }
    return 0;
}
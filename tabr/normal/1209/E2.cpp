#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        // n = m = 12;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), t(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                // if (i == j) a[i][j] = i + 1;
                t[j][i] = a[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            sort(t[i].rbegin(), t[i].rend());
            t[i].emplace_back(i);
        }
        sort(t.rbegin(), t.rend());
        m = min(n, m);
        vector<vector<int>> s(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            int j = t[i].back();
            for (int k = 0; k < n; k++) {
                s[i][k] = a[k][j];
            }
        }
        swap(a, s);
        vector<int> dp(1 << n);
        for (int j = 0; j < m; j++) {
            vector<int> ndp = dp;
            vector<int> cost(1 << n);
            for (int k = 0; k < n; k++) {
                for (int c = 0; c < (1 << n); c++) {
                    int cc = 0;
                    for (int i = 0; i < n; i++) {
                        if (c & (1 << i)) {
                            cc += a[j][(i + k) % n];
                        }
                    }
                    cost[c] = max(cost[c], cc);
                }
            }
            for (int b = 0; b < (1 << n); b++) {
                for (int c = b; c >= 0; c = b & (c - 1)) {
                    int cc = cost[b - c];
                    ndp[b] = max(ndp[b], dp[c] + cc);
                    if (c == 0) {
                        break;
                    }
                }
            }
            swap(ndp, dp);
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
    return 0;
}
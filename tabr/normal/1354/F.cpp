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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        vector<tuple<int, int, int>> p(n);
        for (int i = 0; i < n; i++) {
            int aa, bb;
            cin >> aa >> bb;
            p[i] = tie(bb, aa, i);
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++) {
            tie(b[i], a[i], c[i]) = p[i];
            c[i]++;
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n - k + 1)));
        for (int t = 0; t < n; t++) {
            for (int i = 0; i <= k; i++) {
                int j = t - i;
                if (j < 0 || n - k < j) {
                    continue;
                }
                if (i < k) {
                    dp[t + 1][i + 1][j] = max(dp[t + 1][i + 1][j], dp[t][i][j] + a[t] + b[t] * i);
                }
                if (j < n - k) {
                    dp[t + 1][i][j + 1] = max(dp[t + 1][i][j + 1], dp[t][i][j] + b[t] * (k - 1));
                }
            }
        }
        vector<int> s, t;
        int ci = k, cj = n - k;
        for (int i = n - 1; i >= 0; i--) {
            if (ci != 0 && dp[i][ci - 1][cj] + a[i] + b[i] * (ci - 1) == dp[i + 1][ci][cj]) {
                s.emplace_back(c[i]);
                ci--;
            } else if (cj != 0 && dp[i][ci][cj - 1] + b[i] * (k - 1) == dp[i + 1][ci][cj]) {
                t.emplace_back(c[i]);
                cj--;
            }
            debug(ci, cj);
        }
        assert(ci + cj == 0);
        vector<int> ans;
        if (!s.empty()) {
            ans.emplace_back(s[0]);
            s.erase(s.begin());
        }
        for (int i : t) {
            ans.emplace_back(-i);
            ans.emplace_back(i);
        }
        for (int i : s) {
            ans.emplace_back(i);
        }
        cout << ans.size() << '\n';
        for (int i : vector<int>(ans.rbegin(), ans.rend())) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
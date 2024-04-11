#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const long long mod = (long long) 1e9 + 7;
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = (int) s.size(), m = (int) t.size();
        vector<int> a;
        a.emplace_back(-m);
        for (int i = 0; i <= n - m; i++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != t[j]) {
                    ok = false;
                }
            }
            if (ok) {
                a.emplace_back(i);
            }
        }
        a.emplace_back(n + m);
        n = (int) a.size();
        vector <pair<long long, long long>> dp(n, make_pair(mod, 0));
        dp[0].first = 0;
        dp[0].second = 1;
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i] + m) {
                    continue;
                }
                if (t == -1) {
                    t = a[j];
                }
                if (a[j] < t + m) {
                    if (dp[j].first > dp[i].first + 1) {
                        dp[j] = dp[i];
                        dp[j].first++;
                    } else if (dp[j].first == dp[i].first + 1) {
                        dp[j].second += dp[i].second;
                        dp[j].second %= mod;
                    }
                }
            }
        }
        cout << dp[n - 1].first - 1 << " " << dp[n - 1].second << "\n";
    }
    return 0;
}
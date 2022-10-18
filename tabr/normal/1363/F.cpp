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
    const int inf = 1e9;
    while (tt--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> ac(26);
        vector<vector<int>> p(26);
        for (int i = 0; i < n; i++) {
            p[s[i] - 'a'].emplace_back(i);
            ac[s[i] - 'a']++;
            ac[t[i] - 'a']--;
        }
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (ac[i] != 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> dp(n + 1, inf);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int c = t[i] - 'a';
            vector<bool> ps(n + 1);
            for (int j : p[c]) {
                ps[j] = true;
            }
            int mn = inf;
            for (int j = n; j > p[c].back(); j--) {
                mn = min(dp[j], mn);
                dp[j] = inf;
            }
            for (int j = p[c].back(); j >= 0; j--) {
                if (ps[j]) {
                    int tmp = dp[j];
                    dp[j] = min(dp[j] + 1, mn);
                    mn = min(tmp, mn);
                } else {
                    mn = min(mn, dp[j]);
                    dp[j]++;
                }
            }
            p[c].pop_back();
        }
        cout << dp[0] << '\n';
    }
    return 0;
}
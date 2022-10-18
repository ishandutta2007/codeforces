#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        vector<vector<int>> nxt(n + 1, vector<int>(26, 1000));
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i + 1;
        }
        string ans = "NO";
        rep(q, 1, m) {
            string a = t.substr(0, q), b = t.substr(q);
            debug(a, b);
            vector<vector<int>> dp(q + 1, vector<int>(m - q + 1, 1000));
            dp[0][0] = 0;
            rep(i, 0, q + 1) rep(j, 0, m - q + 1) {
                if (dp[i][j] == 1000) continue;
                if (i != q) dp[i + 1][j] = min(dp[i + 1][j], nxt[dp[i][j]][a[i] - 'a']);
                if (j != m - q) dp[i][j + 1] = min(dp[i][j + 1], nxt[dp[i][j]][b[j] - 'a']);
            }
            debug(dp);
            if (dp[q][m - q] != 1000) {
                ans = "YES";
                break;
            }
        }
        if (m == 1) {
            rep(i, 0, n) {
                if (s[i] == t[0]) {
                    ans = "YES";
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
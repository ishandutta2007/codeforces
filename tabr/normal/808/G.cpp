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
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    int inf = (int)1e9;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
    vector<vector<int>> to(m + 1, vector<int>(26));
    vector<int> p(m);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && t[i] != t[k]) {
            k = p[k - 1];
        }
        if (t[i] == t[k]) {
            k++;
        }
        p[i] = k;
    }
    debug(p);
    to[0][t[0] - 'a'] = 1;
    for (int i = 1; i <= m; i++) {
        to[i] = to[p[i - 1]];
        if (i != m) {
            to[i][t[i] - 'a'] = i + 1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int c = 0; c < 26; c++) {
                if (s[i] != '?' && c != s[i] - 'a') {
                    continue;
                }
                dp[i + 1][to[j][c]] = max(dp[i + 1][to[j][c]], dp[i][j] + (to[j][c] == m));
            }
        }
    }
    debug(to);
    debug(dp);
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
    return 0;
}
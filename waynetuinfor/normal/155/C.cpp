#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int dp[26][maxn];
bool nc[1000][1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<string> forb;
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        string t; cin >> t;
        nc[t[0] - 'a'][t[1] - 'a'] = nc[t[1] - 'a'][t[0] - 'a'] = true;
    }
    int n = s.length();
    for (int i = 0; i < 26; ++i) dp[i][0] = maxn;
    dp[s[0] - 'a'][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) dp[j][i] = dp[j][i - 1] + 1;
        dp[s[i] - 'a'][i] = min(dp[s[i] - 'a'][i], i);
        // for (int j = 0; j < 26; ++j) {
            // for (int k = 0; k < 26; ++k) if (!nc[j][k]) dp[j][i] = min(dp[j][i], dp[k][i - 1]);
            // cout << dp[j][i] << ' ';
        // }         
        for (int j = 0; j < 26; ++j) if (!nc[j][s[i] - 'a']) dp[s[i] - 'a'][i] = min(dp[s[i] - 'a'][i], dp[j][i - 1]);
    }
    int ans = maxn;
    for (int i = 0; i < 26; ++i) ans = min(ans, dp[i][n - 1]);
    cout << ans << endl;
    return 0;
}
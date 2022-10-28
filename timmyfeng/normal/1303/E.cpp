#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        vector<vector<int>> nxt(26, vector<int>(s.size() + 1));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                nxt[j][i] = nxt[j][i + 1];
            }
            nxt[s[i] - 'a'][i] = i + 1;
        }

        bool ok = false;
        vector<vector<int>> dp;
        for (int k = 0; k < t.size() && !ok; k++) {
            string a = t.substr(0, k);
            string b = t.substr(k);
            dp.assign(a.size() + 1, vector<int>(b.size() + 1, 1e9));
            dp[0][0] = 0;
            for (int i = 0; i <= a.size(); i++) {
                for (int j = 0; j <= b.size(); j++) {
                    if (dp[i][j] >= s.size()) continue;
                    if (i < a.size() && nxt[a[i] - 'a'][dp[i][j]]) {
                        dp[i + 1][j] = min(dp[i + 1][j], nxt[a[i] - 'a'][dp[i][j]]);
                    }
                    if (j < b.size() && nxt[b[j] - 'a'][dp[i][j]]) {
                        dp[i][j + 1] = min(dp[i][j + 1], nxt[b[j] - 'a'][dp[i][j]]);
                    }
                }
            }
            ok = dp[a.size()][b.size()] < 1e9;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
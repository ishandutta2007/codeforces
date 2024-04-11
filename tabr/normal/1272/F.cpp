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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), inf = 1e9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(201, inf)));
    tuple<int, int, int, char> p[n + 1][m + 1][201];
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 200; k++) {
                if (dp[i][j][k] == inf) continue;
                int ni = i + (i < n && s[i] == '(');
                int nj = j + (j < m && t[j] == '(');
                if (dp[ni][nj][k + 1] > dp[i][j][k] + 1) {
                    dp[ni][nj][k + 1] = dp[i][j][k] + 1;
                    p[ni][nj][k + 1] = {i, j, k, '('};
                }
            }
            for (int k = 200; k > 0; k--) {
                if (dp[i][j][k] == inf) continue;
                int ni = i + (i < n && s[i] == ')');
                int nj = j + (j < m && t[j] == ')');
                if (dp[ni][nj][k - 1] > dp[i][j][k] + 1) {
                    dp[ni][nj][k - 1] = dp[i][j][k] + 1;
                    p[ni][nj][k - 1] = {i, j, k, ')'};
                }
            }
        }
    }
    int i = n, j = m, k = 0;
    string ans;
    while (i != 0 || j != 0 || k != 0) {
        int ni, nj, nk;
        char c;
        tie(ni, nj, nk, c) = p[i][j][k];
        ans.push_back(c);
        tie(i, j, k) = tie(ni, nj, nk);
    }
    cout << string(ans.rbegin(), ans.rend()) << '\n';
    return 0;
}
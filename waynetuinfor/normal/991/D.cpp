#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
string s[2];
int dp[4][maxn];

void upd(int &v, int c) {
    v = max(v, c);
}

int main() {
    cin >> s[0];
    cin >> s[1];
    int n = s[0].size();
    s[0] = '.' + s[0]; s[1] = '.' + s[1];
    for (int i = 0; i < 4; ++i) fill_n(dp[i], maxn, -maxn);
    dp[3][0] = 0;
    for (int i = 1; i <= n; ++i) {
        upd(dp[0][i], dp[0][i - 1]), upd(dp[0][i], dp[1][i - 1]);
        upd(dp[0][i], dp[2][i - 1]), upd(dp[0][i], dp[3][i - 1]);
        if (s[0][i] == '0' && s[1][i] == '0' && s[0][i - 1] == '0') upd(dp[3][i], dp[2][i - 1] + 1), upd(dp[3][i], dp[0][i - 1] + 1); 
        if (s[0][i] == '0' && s[1][i] == '0' && s[1][i - 1] == '0') upd(dp[3][i], dp[1][i - 1] + 1), upd(dp[3][i], dp[0][i - 1] + 1); 
        if (s[0][i - 1] == '0' && s[1][i - 1] == '0' && s[0][i] == '0') upd(dp[1][i], dp[0][i - 1] + 1);
        if (s[0][i - 1] == '0' && s[1][i - 1] == '0' && s[1][i] == '0') upd(dp[2][i], dp[0][i - 1] + 1);
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) ans = max(ans, dp[i][n]);
    cout << ans << endl;
    return 0;
}
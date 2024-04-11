#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[n + 2][4];
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j < 4; j++) dp[i][j] = -1;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int c = (s[i - 1] == '(' ? 1 : -1);
        for (int j = 0; j < 4; j++) {
            if (dp[i - 1][j] != -1 && dp[i - 1][j] + c >= 0) dp[i][j] = dp[i - 1][j] + c;
        }
        if (s[i - 1] == '(' && dp[i - 1][0] != -1) dp[i][1] = dp[i - 1][0];
        if (s[i - 1] == ')' && dp[i - 1][0] != -1) dp[i][2] = dp[i - 1][0];
        if (dp[i][1] != -1) dp[i][3] = dp[i][1] + 1;
        if (dp[i][2] > 0) dp[i][3] = dp[i][2] - 1;
    }
    if (dp[n][3] == 0) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}
#include <iostream>
 
using namespace std;

const int MAX_N = 207;
const long long M = 1e9 + 7;
long long dp[MAX_N][MAX_N][MAX_N];
 
int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= s.length(); k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    int prevv[s.length()];
    prevv[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        string t = "";
        for (int j = 0; j < i; j++) t += s[j];
        if (s[i] == '(') t += ')';
        else t += '(';
        prevv[i] = 0;
        for (int j = 1; j <= i; j++) {
            bool flag = 1;
            for (int k = 0; k < j; k++) {
                if (s[k] != t[t.length() - (j - k)]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) prevv[i] = j;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < s.length(); k++) {
                //cout << i << ' ' << j << ' ' << k << endl;
                if (dp[i][j][k] == 0) continue;
                if (s[k] == '(') {
                    if (j < n) dp[i + 1][j + 1][k + 1] = (dp[i][j][k] + dp[i + 1][j + 1][k + 1]) % M;
                    if (j > 0) dp[i + 1][j - 1][prevv[k]] = (dp[i + 1][j - 1][prevv[k]] + dp[i][j][k]) % M;
                } else {
                    if (j < n) dp[i + 1][j + 1][prevv[k]] = (dp[i + 1][j + 1][prevv[k]] + dp[i][j][k]) % M;
                    if (j > 0) dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + dp[i][j][k]) % M;
                }
            }
            //cout << i << ' ' << j << ' ' << dp[i][j][s.length()] << endl;
            if (j < n) dp[i + 1][j + 1][s.length()] = (dp[i + 1][j + 1][s.length()] + dp[i][j][s.length()]) % M;
            if (j > 0) dp[i + 1][j - 1][s.length()] = (dp[i + 1][j - 1][s.length()] + dp[i][j][s.length()]) % M;
        }
    }
    //cout << dp[3][3][2] << endl;
    cout << dp[2 * n][0][s.length()] << endl;
    return 0;
}
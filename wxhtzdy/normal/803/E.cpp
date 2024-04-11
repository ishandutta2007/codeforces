#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, k;
string s;
bool dp[maxn][2 * maxn + 5][3];
int delta[3] = {-1, 0, 1};
void rec(int pos, int bal, int c) {
    if (pos > 0) {
        for (int x = 0; x < 3; x++) {
            if (dp[pos - 1][bal - delta[c]][x]) {
                rec(pos - 1, bal - delta[c], x);
                break;
            }
        }
    }
    cout << (c == 0 ? 'L' : (c == 1 ? 'D' : 'W'));
}
int main() {
    cin >> n >> k >> s;
    if (k == 1) {
        if (n > 1) {
            cout << "NO";
            return 0;
        }
        cout << (s[0] != '?' ? s[0] : 'W');
        return 0;
    }
    if (s[0] == 'L' || s[0] == '?') dp[0][maxn - 1][0] = true;
    if (s[0] == 'D' || s[0] == '?') dp[0][maxn][1] = true;
    if (s[0] == 'W' || s[0] == '?') dp[0][maxn + 1][2] = true;
    for (int i = 1; i < n; i++) {
        int L = maxn - k + 1, R = maxn + k - 1;
        if (i == n - 1) L--, R++;
        for (int j = L; j <= R; j++) {
            if (s[i] == 'L' || s[i] == '?') {
                for (int x = 0; x < 3; x++) dp[i][j][0] |= dp[i - 1][j + 1][x];
            }
            if (s[i] == 'D' || s[i] == '?') {
                for (int x = 0; x < 3; x++) dp[i][j][1] |= dp[i - 1][j][x];
            }
            if (s[i] == 'W' || s[i] == '?') {
                for (int x = 0; x < 3; x++) dp[i][j][2] |= dp[i - 1][j - 1][x];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (dp[n - 1][maxn + k][i]) {
            rec(n - 1, maxn + k, i);
            return 0;
        }
        if (dp[n - 1][maxn - k][i]) {
            rec(n - 1, maxn - k, i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
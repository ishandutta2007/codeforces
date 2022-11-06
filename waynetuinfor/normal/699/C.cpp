#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], dp[3][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) fill(dp[i], dp[i] + maxn, n + 1);
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) dp[0][i] = min(dp[0][i], dp[j][i - 1] + 1);
        if (a[i] == 1) {
            dp[1][i] = min({ dp[1][i], dp[0][i - 1], dp[2][i - 1] });
        } 
        if (a[i] == 2) {
            dp[2][i] = min({ dp[2][i], dp[0][i - 1], dp[1][i - 1] });
        }
        if (a[i] == 3) {
            dp[2][i] = min({ dp[2][i], dp[0][i - 1], dp[1][i - 1] });
            dp[1][i] = min({ dp[1][i], dp[0][i - 1], dp[2][i - 1] });
        }
    }
    cout << min({ dp[0][n], dp[1][n], dp[2][n] }) << '\n';
    return 0;
}
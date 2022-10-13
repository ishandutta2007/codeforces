#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
int dp[maxN][maxN];
int what[maxN][maxN];
int n;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j) {
                dp[i][j] = true;
                what[i][j] = a[i];
            }
            else {
                dp[i][j] = j - i + 1;
            }
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (dp[i][k] == 1 && dp[k + 1][j] == 1 && what[i][k] == what[k + 1][j]) {
                    dp[i][j] = 1;
                    what[i][j] = what[i][k] + 1;
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
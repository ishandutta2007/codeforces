#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, dp[MAXN][MAXN];
string s;

int main() {
    cin >> n >> s;

    for(int len = 1; len <= n; ++len) {
        for(int l = 0; l <= n - len; ++l) {
            int r = l + len - 1;
            if (len == 1)
                dp[l][r] = 1;
            else {
                dp[l][r] = dp[l][r-1] + (s[l] != s[r]);
                for(int i = l; i < r; ++i)
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
            }
        }
    }

    printf("%d", dp[0][n-1]);

    return 0;
}
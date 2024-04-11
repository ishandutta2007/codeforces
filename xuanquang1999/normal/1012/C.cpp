#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
const int oo = 1000000007;

int n, a[MAXN], dp[MAXN][MAXN], minDP[MAXN][MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= n; ++i) {
            if (j == 1)
                dp[i][j] = max(a[i-1] - a[i] + 1, 0) + max(a[i+1] - a[i] + 1, 0);
            else {
                dp[i][j] = oo;

                if (i >= 3) {
                    // k = i-2
                    int x = min(a[i-1], a[i-2] - 1);
                    dp[i][j] = min(dp[i][j], dp[i-2][j-1] + max(x - a[i] + 1, 0) + max(a[i+1] - a[i] + 1, 0));
                }
                if (i >= 4) {
                    dp[i][j] = min(dp[i][j], minDP[i-3][j-1] + max(a[i-1] - a[i] + 1, 0) + max(a[i+1] - a[i] + 1, 0));
                }
            }

//            printf("%d ", dp[i][j]);
            minDP[i][j] = dp[i][j];
            if (i >= 2)
                minDP[i][j] = min(minDP[i][j], minDP[i-1][j]);
        }

//        puts("");
    }

    for(int j = 1; j <= (n+1)/2; ++j)
        printf("%d ", minDP[n][j]);

    return 0;
}
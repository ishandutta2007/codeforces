#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int inf = 1e9;
int a[maxn], f[maxn][2], b[maxn], dp[maxn][2];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < maxn; ++i) {
        dp[i][0] = -inf;
        dp[i][1] = inf;
    }
    dp[0][0] = inf;
    dp[0][1] = -inf;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1] && dp[i - 1][0] > dp[i][0]) {
            dp[i][0] = dp[i - 1][0];
            f[i][0] = 0;
        }
        if (a[i] > dp[i - 1][1] && a[i - 1] > dp[i][0]) {
            dp[i][0] = a[i - 1];
            f[i][0] = 1;
        }
        if (a[i] < a[i - 1] && dp[i - 1][1] < dp[i][1]) {
            dp[i][1] = dp[i - 1][1];
            f[i][1] = 0;
        }
        if (a[i] < dp[i - 1][0] && a[i - 1] < dp[i][1]) {
            dp[i][1] = a[i - 1];
            f[i][1] = 1;
        }
    } 
    if (dp[n - 1][0] == -inf && dp[n - 1][1] == inf) {
        puts("NO");
        return 0;
    }
    int p = dp[n - 1][0] > -inf ? 0 : 1;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = p;
        p ^= f[i][p];
    }
    puts("YES");
    for (int i = 0; i < n; ++i) 
        printf("%d ", b[i]);
    puts("");
    return 0;
}
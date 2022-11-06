#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int mod = 998244353;
int dp[maxn][maxn * maxn], a[maxn], c[maxn];
int cnk[maxn][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        c[a[i]]++;
    }
    sort(a, a + n);
    dp[0][0] = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        for (int j = i + 1; j > 0; --j) {
            for (int k = sum; k >= a[i]; --k) {
                dp[j][k] += dp[j - 1][k - a[i]];
                if (dp[j][k] >= mod) dp[j][k] -= mod;
            }
        } 
    }
    cnk[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        cnk[i][0] = cnk[i - 1][0];
        for (int j = 1; j < maxn; ++j) {
            cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
            if (cnk[i][j] >= mod) cnk[i][j] -= mod;
        }
    }
    int ans = 0, diff = 0;
    for (int i = 0; i < maxn; ++i) if (c[i]) ++diff;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 1; j <= c[i]; ++j) {
            if (dp[j][i * j] == cnk[c[i]][j]) {
                ans = max(ans, j);
                if (diff == 2 && j == c[i]) ans = max(ans, n);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
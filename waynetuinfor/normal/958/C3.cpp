#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5, maxp = 100 + 5;
const int inf = 1e9;
int a[maxn], s[maxn];
int dp[2][maxn], t[maxp];

int main() {
    int n, k, p; scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = (s[i - 1] + a[i]) % p;
    if (n <= k * p) {
        fill(dp[0], dp[0] + maxn, inf);
        dp[0][0] = 0;
        int z = 0;
        for (int i = 1; i <= k; ++i) {
            fill(t, t + maxp, inf);
            z ^= 1;
            fill(dp[z], dp[z] + maxn, inf);
            for (int j = 1; j <= n; ++j) {
                t[s[j - 1]] = min(t[s[j - 1]], dp[z ^ 1][j - 1]);
                for (int r = 0; r < p; ++r) dp[z][j] = min(dp[z][j], t[r] + (s[j] - r + p) % p);
            }
        }
        printf("%d\n", dp[z][n]);
        return 0;
    }
    fill(t, t + maxp, 0);
    int lis = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s[i]; ++j) dp[0][i] = max(dp[0][i], t[j] + 1);
        t[s[i]] = max(t[s[i]], dp[0][i]);
    }
    if (dp[0][n] >= k) printf("%d\n", s[n]);
    else printf("%d\n", s[n] + p);
    return 0;
}
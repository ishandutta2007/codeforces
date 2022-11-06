#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int mod = 998244353;
int a[maxn], dp[maxn][maxn], sum[maxn][maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int s = 1; s * (k - 1) <= a[n]; ++s) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j)
                sum[i][j] = 0;
        }
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            while (p < i && a[i] - a[p + 1] >= s) ++p;
            dp[i][1] = 1;
            for (int j = 2; j <= k; ++j) dp[i][j] = sum[p][j - 1];
            for (int j = 1; j <= k; ++j) sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
        }
        (ans += sum[n][k]) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}
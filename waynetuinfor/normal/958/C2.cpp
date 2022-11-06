#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5, maxp = 100 + 5;
const long long inf = 1e15;
int a[maxn], s[maxn];
long long dp[2][maxn];
long long t[maxp];

int main() {
    int n, k, p; scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        s[i] = (s[i - 1] + a[i]) % p;
    }
    fill(dp[0], dp[0] + maxn, -inf);
    dp[0][0] = 0;
    int r = 0;
    for (int i = 1; i <= k; ++i) {
        r ^= 1;
        fill(t, t + maxp, -inf); 
        fill(dp[r], dp[r] + maxn, -inf);
        for (int j = 1; j <= n; ++j) {
            t[s[j - 1]] = max(t[s[j - 1]], dp[r ^ 1][j - 1]);
            for (int z = 0; z < p; ++z) if (t[z] != -inf) {
                dp[r][j] = max(dp[r][j], t[z] + (s[j] - z + p) % p);
            }
        }
    }
    printf("%lld\n", dp[r][n]);
    return 0;
}
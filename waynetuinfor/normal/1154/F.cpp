#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int maxk = 2000 + 5;
int a[maxn], d[maxk];
long long s[maxk], dp[maxk];

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        if (x <= k) 
            d[x] = max(d[x], y);
    }

    for (int i = 1; i <= k; ++i)
        s[i] = s[i - 1] + a[i];

    for (int i = 1; i <= k; ++i)
        dp[i] = 1e18;

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (d[j] > 0)
                dp[i] = min(dp[i], dp[i - j] + s[i] - s[i - j + d[j]]);
            dp[i] = min(dp[i], dp[i - 1] + a[i]);
        }
    }

    printf("%lld\n", dp[k]);
    return 0;
}
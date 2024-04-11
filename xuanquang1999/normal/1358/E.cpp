#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, m, a[MAXN], x;
long long d[MAXN], dp[MAXN];

int main() {
    scanf("%d", &n);
    m = (n+1)/2;
    for(int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for(int i = m + 1; i <= n; ++i)
        a[i] = x;
    
    for(int i = 1; i <= n; ++i)
        d[i] = d[i-1] + a[i];

    // for(int i = 1; i <= n; ++i)
    //     printf("%d %lld\n", a[i], d[i]);

    int k = n/2 + 1;
    for(int i = 1; i <= m; ++i) {
        dp[i] = d[i+k-1] - d[i-1];
        if (i > 1)
            dp[i] = min(dp[i-1], dp[i]);

        if (dp[i] + 1LL*(m-i)*x > 0) {
            printf("%d\n", k + (m-i));
            return 0;
        }
    }

    puts("-1");

    return 0;
}
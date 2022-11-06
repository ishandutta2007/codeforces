#include <cstdio>
int dp[1001][60001];
int c[1001];
int main() {
    dp[0][0] = 1;
    for(int n=1; n<=1000; n++) {
        for(int i=0; i<=49*n; i++) {
            if(dp[n-1][i]) {
                dp[n][i] = dp[n][i+4] = dp[n][i+9] = dp[n][i+49] = 1;
            }
            if(dp[n][i]) c[n]++;
        }
    }
    int n;
    scanf("%d", &n);
    if(n < 1000) {
        printf("%d\n", c[n]);
    }
    else {
        long long ans = 49ll*n;
        ans -= 49000;
        ans += c[1000];
        printf("%lld\n", ans);
    }
    return 0;
}
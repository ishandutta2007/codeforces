#include <cstdio>
char a[1000010];
char b[1000010];
int dp[1000001][2];
int min(int x, int y){return x>y?y:x;}
int main() {
    int n;
    scanf("%d%s%s", &n, a+1, b+1);
    for(int i=1; i<=n; i++) {
        a[i] -= '0';
        b[i] -= '0';
    }
    dp[0][b[1]] = 0;
    dp[0][!b[1]] = 1;
    for(int i=1; i<=n; i++) {
        dp[i][0] = dp[i][1] = 10000000;
        for(int k=0; k<2; k++) {
            if(a[i] == k) dp[i][b[i+1]] = min(dp[i][b[i+1]], dp[i-1][k]);
            else dp[i][b[i+1]] = min(dp[i][b[i+1]], dp[i-1][k]+1);
            if(a[i] == b[i+1]) dp[i][k] = min(dp[i][k], dp[i-1][k]+1);
        }
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));
    return 0;
}
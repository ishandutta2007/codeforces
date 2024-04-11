#include<stdio.h>
int dp[2][501][501];
int a[501];
int main()
{
    int n, m, b, M;
    int i, j, k;
    scanf("%d%d%d%d", &n, &m, &b, &M);
    for(i=1; i<=n; i++) scanf("%d", a+i);
    dp[0][0][0] = 1;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            for(k=0; k<=b; k++)
            {
                dp[i&1][j][k] = (dp[1-(i&1)][j][k])%M;
                if(j-1>=0 && k-a[i]>=0) dp[i&1][j][k] = (dp[i&1][j][k] + dp[i&1][j-1][k-a[i]])%M;
            }
        }
    }
    int ans = 0;
    for(k=0; k<=b; k++) ans = (ans + dp[n&1][m][k])%M;
    printf("%d", ans);
    return 0;
}
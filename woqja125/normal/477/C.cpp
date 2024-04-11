#include<stdio.h>
#include<string.h>
char s[2010], p[510];
int dp[2010][2010];
int pt[2010][510];
int latest[510];
int ans[2010];
int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int n, m, i, j;
    scanf("%s%s", s, p);
    n = strlen(s);
    m = strlen(p);
    for(j=0; j<m; j++)latest[j] = -1;
    for(i=0; i<n; i++)
    {
        for(j=m-1; j>=0; j--)
        {
            pt[i][j] = -1;
            if(s[i] == p[j])
            {
                if(j==0)
                {
                    pt[i][j] = i;
                    latest[0] = i;
                }
                else
                {
                    if(latest[j-1] != -1)
                    {
                        pt[i][j] = pt[latest[j-1]][j-1];
                        latest[j] = i;
                    }
                }
            }
        }
    }
    dp[0][0] = 0;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=i; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j!=0) dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
            if(pt[i-1][m-1] == -1)continue;
            int p = j - (i - pt[i-1][m-1] - m);
            if(p >= 0 && pt[i-1][m-1] >= p) dp[i][j] = max(dp[i][j], dp[pt[i-1][m-1]][p] + 1);
        }
    }
    for(i=0; i<=n; i++)printf("%d ", dp[n][i]);
    return 0;
}
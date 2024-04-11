#include <bits/stdc++.h>
using namespace std;

const int N = 101, M = 1001;
int x[M];
double dp[N][N*M];

int main()
{
    int n, m, s = 0;
    scanf("%d %d", &n, &m);
    if(m == 1)
    {
        puts("1");
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", x + i);
        s += x[i];
    }
    for(int i = 0; i <= n*m; i++)
        dp[0][i] = m - 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n*m; j++)
        {
            dp[i][j] = dp[i-1][j-1] - (j-m-1 >= 0 ? dp[i-1][j-m-1] : 0);
            if(j-x[i] == 0) dp[i][j] -= dp[i-1][j-x[i]];
            if(j-x[i] > 0) dp[i][j] -= dp[i-1][j-x[i]] - dp[i-1][j-x[i]-1];
            dp[i][j] /= m - 1;
            dp[i][j] += dp[i][j-1];
//             printf("dp[%d][%d] = %lf\n", i, j, dp[i][j]);
        }
    printf("%.10lf\n", dp[n][s-1] + 1);
}
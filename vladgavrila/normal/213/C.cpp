#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 310
#define inf 1000000000

int n;
int dp[2][maxn][maxn];
int v[maxn][maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d", &v[i][j]);

    for(int i=0; i<2; ++i)
        for(int j=1; j<=n; ++j)
            for(int k=1; k<=n; ++k)
                dp[i][j][k]=-inf;

    dp[1][1][1]=0;
    for(int r=1; r<=n; ++r)
    {
        for(int i=1; i<=n; ++i)
            for(int j=i; j<=n; ++j)
            {
                dp[0][i][j]=dp[1][i][j];
                dp[1][i][j]=-inf;
                if(dp[0][i][j]!=-inf)
                    dp[0][i][j]+=v[r][i];
            }

        for(int i=1; i<=n; ++i)
            for(int j=i; j<=n; ++j)
            {
                if(dp[0][i][j]==-inf)
                    continue;

                if(i<j)
                    dp[1][i][j]=max(dp[1][i][j], dp[0][i][j]+v[r][j]);
                else
                    dp[1][i][j]=max(dp[1][i][j], dp[0][i][j]);

                dp[0][i+1][max(i+1, j)]=max(dp[0][i+1][max(i+1, j)], dp[0][i][j]+v[r][i+1]);
            }

        for(int i=1; i<=n; ++i)
            for(int j=i; j<=n; ++j)
            {
                if(dp[1][i][j]==-inf)
                    continue;
                dp[1][i][j+1]=max(dp[1][i][j+1], dp[1][i][j]+v[r][j+1]);
            }
    }

    printf("%d\n", dp[1][n][n]);

    return 0;
}
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MOD = 1000000007;
char a[2001][2001];
int n, m, dp[2][2001][2001], cnt[2][2001][2001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        getchar();
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &a[i][j]);
        }
    }
    if (n == 1 && m == 1)
    {
        printf("1");
        return 0;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (i == n)
            {
                if (a[i][j] == 'R')
                {
                    cnt[0][i][j] = 1;
                }
                else
                {
                    cnt[0][i][j] = 0;
                }
            }
            else
            {
                cnt[0][i][j] = cnt[0][i + 1][j] + (a[i][j] == 'R');
            }
            if (j == m)
            {
                if (a[i][j] == 'R')
                {
                    cnt[1][i][j] = 1;
                }
                else
                {
                    cnt[1][i][j] = 0;
                }
            }
            else
            {
                cnt[1][i][j] = cnt[1][i][j + 1] + (a[i][j] == 'R');
            }
        }
    }
    dp[0][1][1] = dp[1][1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j != 1 && !(j == 2 && i == 1))
            {
                dp[0][i][j] = (dp[0][i][j] + dp[0][i][j - 1]) % MOD;
            }
            dp[1][i + 1][j] = (dp[1][i + 1][j] + dp[0][i][j]) % MOD;
            int c = cnt[0][i + 1][j];
            dp[1][n - c + 1][j] = (dp[1][n - c + 1][j] - dp[0][i][j] + MOD) % MOD;
            if (i != 1 && !(i == 2 && j == 1))
            {
                dp[1][i][j] = (dp[1][i][j] + dp[1][i - 1][j]) % MOD;
            }
            dp[0][i][j + 1] = (dp[0][i][j + 1] + dp[1][i][j]) % MOD;
            c = cnt[1][i][j + 1];
            dp[0][i][m - c + 1] = (dp[0][i][m - c + 1] - dp[1][i][j] + MOD) % MOD;
        }
    }
    printf("%d", (dp[0][n][m] + dp[1][n][m]) % MOD);
    return 0;
}
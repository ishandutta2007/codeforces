#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100001][2][3];

char s[100001];

int main()
{
    int n;
    scanf("%d %s", &n, s);
    for(int i = 1; i <= n; i++)
    {
	int a = s[i-1] - '0', b = 1 - a;
	for(int j = 0; j < 3; j++)
	{
	    dp[i][a][j] = max(dp[i-1][a][j], dp[i-1][b][j] + 1);
	    dp[i][b][j] = dp[i-1][b][j];
	    if(j > 0)
	    {
		dp[i][a][j] = max(dp[i][a][j], dp[i-1][a][j-1] + 1);
		dp[i][b][j] = max(dp[i][b][j], dp[i-1][b][j-1] + 1);
	    }
	}
    }
    int ans = 0;
    for(int i = 0; i < 2; i++)
	for(int j = 0; j < 3; j++)
	    ans = max(ans, dp[n][i][j]);
    printf("%d\n", ans);
}
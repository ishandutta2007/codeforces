#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 500;
int c[N];
int dp[N][N+1];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
	scanf("%d", c + i);
    for(int i = n - 1; i >= 0; i--)
    {
	dp[i][i+1] = 1;
	if(i < n - 1) dp[i][i+2] = 1 + (c[i] != c[i+1]);
	for(int j = i + 3; j <= n; j++)
	{
	    dp[i][j] = dp[i][j-1] + 1;
	    for(int k = i + 1; k < j; k++)
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	    if(c[i] == c[j-1]) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
	}
    }
    printf("%d\n", dp[0][n]);
}
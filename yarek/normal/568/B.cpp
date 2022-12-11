#include <cstdio>

int newton[4001][4001];
long long dp[4001];
const long long mod = 1000000007;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
    {
	newton[i][0] = 1;
	for(int j = 1; j <= i; j++)
	    newton[i][j] = (newton[i-1][j-1] + newton[i-1][j]) % mod;
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
	for(int j = 1; j <= i; j++)
	    dp[i] = (dp[i] + dp[i-j] * newton[i-1][j-1]) % mod;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
	ans = (ans + dp[i] * newton[n][i]) % mod;
    printf("%d\n", ans);
}
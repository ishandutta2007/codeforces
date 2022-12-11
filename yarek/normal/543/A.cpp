#include <cstdio>
#include <algorithm>
using namespace std;

int dp[501][501];

int main()
{
    int n, m, b, mod, a;
    scanf("%d %d %d %d", &n, &m, &b, &mod);
    dp[0][0] = 1;
    while(n--)
    {
	scanf("%d", &a);
	for(int i = 0; i < m; i++)
	    for(int j = 0; j <= b - a; j++)
		dp[i+1][j+a] = (dp[i+1][j+a] + dp[i][j]) % mod;
    }
    int ans = 0;
    for(int i = 0; i <= b; i++)
	ans = (ans + dp[m][i]) % mod;
    printf("%d\n", ans);
}
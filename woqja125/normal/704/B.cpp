#include<stdio.h>
const int MAX = 5010;
long long x[MAX], a[MAX], b[MAX], c[MAX], d[MAX];
long long dp[MAX][MAX];
long long min(long long a, long long b){ return a>b?b:a; }
long long abs(long long x){ return x>0?x:-x; }
int main()
{
	int n, s, e;
	scanf("%d%d%d", &n, &s, &e);
	for(int i=1; i<=n; i++) scanf("%lld", x+i);
	for(int i=1; i<=n; i++) scanf("%lld", a+i);
	for(int i=1; i<=n; i++) scanf("%lld", b+i);
	for(int i=1; i<=n; i++) scanf("%lld", c+i);
	for(int i=1; i<=n; i++) scanf("%lld", d+i);
	
	for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)dp[i][j] = 1000000000000000000ll;

	int dt = 0;
	if(s!=1 && e!=1) dp[1][1] = 0ll-x[1]+b[1] -x[1]+d[1];
	else if(s==1)
	{
		dp[1][1] = 0ll-x[1]+d[1];
		dt = -1;
	}
	else
	{
		dp[1][0] = 0ll-x[1]+b[1];
		dt = 1;
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<i; j++) // j : from 1~i
		{
			if(j <= 0 && j+dt <= 0) continue;
			if(i == s)
			{
				dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] + -x[i]+d[i]);
				if(j+dt > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + x[i]+c[i]);
			}
			else if(i == e)
			{
				dp[i][j] = min(dp[i][j], dp[i-1][j] - x[i] + b[i]);
				if(j>0) dp[i][j-1] = min(dp[i][j-1], dp[i-1][j] + x[i]+a[i]);
			}
			else
			{
				if(j>0 && j+dt>0) dp[i][j-1] = min(dp[i][j-1], dp[i-1][j] + x[i]+a[i] + x[i]+c[i]);
				if(j+dt > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + b[i] + c[i]);
				if(j>0) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i] + d[i]);
				dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] -x[i]+b[i] -x[i]+d[i]);
			}
		}
		if(i==s) dt--;
		if(i==e) dt++;
	}
	printf("%lld", dp[n][0]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int dp[2][155][6000];
int n, k, s, T[155], P[155];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &k, &s);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", T+i);
		P[i]=P[i-1]+T[i];
	}
	s=min(s, ((n+1)/2)*((n+1)/2));
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			for(int k=0; k<=s; k++)
			{
				if(i==j || k==0)
				{
					dp[i%2][j][k]=P[j];
					continue;
				}
				dp[i%2][j][k]=dp[(i+1)%2][j][k];
				if(k>0)
					dp[i%2][j][k]=min(dp[i%2][j][k], dp[i%2][j][k-1]);
				if(k>=(i-j))
					dp[i%2][j][k]=min(dp[i%2][j][k], dp[(i+1)%2][j-1][k-(i-j)]+T[i]);
				//printf("%d %d %d: %d\n", i, j, k, dp[i%2][j][k]);
			}
		}
	}
	printf("%d\n", dp[n%2][k][s]);
	return 0;
}
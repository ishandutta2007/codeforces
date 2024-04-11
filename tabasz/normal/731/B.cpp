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

int n, T[200005], dp[200005][2];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		if(T[i]%2)
		{
			dp[i][0]=dp[i-1][1];
			dp[i][1]=dp[i-1][0];
		}
		else
		{
			dp[i][0]=dp[i-1][0];
			if(T[i]>0)
				dp[i][1]=dp[i-1][1];
		}
	}
	if(dp[n][0])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
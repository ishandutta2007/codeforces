#include <stdio.h>
const int N=100050;
int cnt[2][2][N],d[N];
char s[N];
bool can[N];
int dp[N],cost[N];
int main()
{
	int n,m,i;
	scanf("%i %s %i",&n,s+1,&m);
	for(i=1;i<=n;i++)
	{
		d[i]=d[i-1];
		cnt[0][0][i]=cnt[0][0][i-1];
		cnt[0][1][i]=cnt[0][1][i-1];
		cnt[1][0][i]=cnt[1][0][i-1];
		cnt[1][1][i]=cnt[1][1][i-1];
		if(s[i]=='?') d[i]++;
		if(s[i]=='a') cnt[i&1][0][i]++;
		if(s[i]=='b') cnt[i&1][1][i]++;
	}
	for(i=1;i<=n-m+1;i++)
	{
		if(cnt[i&1][1][i-1]==cnt[i&1][1][i+m-1] && cnt[(i&1)^1][0][i-1]==cnt[(i&1)^1][0][i+m-1]) can[i]=1;
	}
	for(i=1;i<=n-m+1;i++)
	{
		if(can[i])
		{
			if(i<m) dp[i]=1,cost[i]=d[i+m-1]-d[i-1];
			else dp[i]=dp[i-m]+1,cost[i]=cost[i-m]+d[i+m-1]-d[i-1];
		}
		if(dp[i-1]>dp[i]) dp[i]=dp[i-1],cost[i]=cost[i-1];
		else if(dp[i-1]==dp[i] && cost[i-1]<cost[i]) cost[i]=cost[i-1];
		//printf("can:%i dp:%i cost:%i\n",can[i],dp[i],cost[i]);
	}
	printf("%i\n",cost[n-m+1]);
	return 0;
}
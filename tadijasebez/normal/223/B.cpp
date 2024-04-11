#include <stdio.h>
#include <cstring>
const int N=200050;
int dp[N][2],last[N],dp1[N],dp2[N];
char s[N],t[N];
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	int i,n,m;
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]+(t[dp[i-1][0]+1]==s[i]?1:0);
		if(t[dp[i-1][0]+1]==s[i])
		{
			dp1[i]=dp[i][0];
		}
		else dp1[i]=dp1[last[s[i]]];
		last[s[i]]=i;
	}
	dp[n+1][1]=m+1;
	dp2[n+1]=m+1;
	for(i=0;i<N;i++) last[i]=n+1;
	for(i=n;i>=0;i--)
	{
		dp[i][1]=dp[i+1][1]+(t[dp[i+1][1]-1]==s[i]?-1:0);
		if(t[dp[i+1][1]-1]==s[i])
		{
			dp2[i]=dp[i][1];
		}
		else dp2[i]=dp2[last[s[i]]];
		last[s[i]]=i;
	}
	bool ok=1;
	for(i=1;i<=n;i++) if(dp1[i]<dp2[i]) ok=0;
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}
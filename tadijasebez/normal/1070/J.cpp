#include <bits/stdc++.h>
using namespace std;
const int N=30050;
const int inf=1e9+7;
int dp[N],cnt[26];
void Run()
{
	for(int i=0;i<26;i++) cnt[i]=0;
	int n,m,k;
	string s;
	scanf("%i %i %i",&n,&m,&k);
	cin >> s;
	for(char c:s) cnt[c-'A']++;
	int ans=inf;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++) dp[j]=inf;
		dp[n]=m;
		for(int j=0;j<26;j++) if(i!=j)
		{
			for(int k=0;k<=n;k++)
			{
				dp[k]=max(0,dp[k]-cnt[j]);
				if(k+cnt[j]<=n) dp[k]=min(dp[k],dp[k+cnt[j]]);
			}
		}
		for(int k=0;k<=n;k++) if(k+dp[k]<=cnt[i]) ans=min(ans,k*dp[k]);
	}
	printf("%i\n",ans);
}
int main()
{
	int t;scanf("%i",&t);
	while(t--) Run();
	return 0;
}
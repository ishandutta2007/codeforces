#include<bits/stdc++.h>
using namespace std;
int k;
const int max_n=2e3+5;
const int max_m=2e3+5;
double dp[max_n][max_m];
const int mod=1e9+7;
int ans[max_n][max_m];
bool vis[max_n][max_m];
void calc(int n,int m)
{
	assert(m>=0&&m<=n);
	if(vis[n][m])
		return;
	vis[n][m]=true;
	if(m==0)
		dp[n][m]=0,ans[n][m]=0;
	else if(m==n)
		dp[n][m]=1ll*n*k,ans[n][m]=1ll*n*k%mod;
	else
	{
		calc(n-1,m-1),calc(n-1,m);
		if(dp[n-1][m-1]>=dp[n-1][m])
			dp[n][m]=dp[n-1][m],ans[n][m]=ans[n-1][m];
		else if(dp[n-1][m]-dp[n-1][m-1]<=2*k)
		{
			dp[n][m]=(dp[n-1][m]+dp[n-1][m-1])*0.5;
			ans[n][m]=ans[n-1][m]+ans[n-1][m-1];
			ans[n][m]-=ans[n][m]>=mod?mod:0;
			if(ans[n][m]&1)
				ans[n][m]+=mod;
			ans[n][m]>>=1;
		}
		else
		{
			dp[n][m]=dp[n-1][m-1]+k;
			ans[n][m]=ans[n-1][m-1]+k;
			ans[n][m]-=ans[n][m]>=mod?mod:0;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)
			for(int j=0;j<=i;++j)
				vis[i][j]=false;
		calc(n,m);
		printf("%d\n",ans[n][m]);
	}
	return 0;
}
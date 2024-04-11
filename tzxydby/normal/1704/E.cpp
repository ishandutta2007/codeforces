#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353,mod1=1e9+7,mod2=1e9+9;
int n,m,a[N],d[N],q[N],ed,dp[N][N],dp1[N][N],dp2[N][N];
vector<int>e[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		d[i]=0;
		e[i].clear();
		for(int j=0;j<=n+1;j++)
			dp[i][j]=dp1[i][j]=dp2[i][j]=0;
	}
	ed=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		d[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
			q[++ed]=i;
	for(int i=1;i<=n;i++)
	{
		int u=q[i];
		for(auto v:e[u])
		{
			d[v]--;
			if(!d[v])
				q[++ed]=v;
		}
	}	
	for(int i=1;i<=n;i++)
		dp[i][0]=a[i]%mod,dp1[i][0]=a[i]%mod1,dp2[i][0]=a[i]%mod2;
	for(int p=1;p<=n;p++)
	{
		int u=q[p];
		for(int i=0;i<=n;i++)
		{
			if(dp[u][i]>1||dp1[u][i]>1||dp2[u][i]>1)
			{
				dp[u][i+1]=(1ll*dp[u][i+1]+dp[u][i]-1+mod)%mod;
				dp[u][i]=1;
				dp1[u][i+1]=(1ll*dp1[u][i+1]+dp1[u][i]-1+mod1)%mod1;
				dp1[u][i]=1;
				dp2[u][i+1]=(1ll*dp2[u][i+1]+dp2[u][i]-1+mod2)%mod2;
				dp2[u][i]=1;
			}
		}
		for(auto v:e[u])
		{
			for(int i=0;i<=n;i++)
			{
				dp[v][i+1]=(dp[v][i+1]+dp[u][i])%mod;
				dp1[v][i+1]=(dp1[v][i+1]+dp1[u][i])%mod1;
				dp2[v][i+1]=(dp2[v][i+1]+dp2[u][i])%mod2;
			}
			dp[v][n+1]=(dp[v][n+1]+dp[u][n+1])%mod;
			dp1[v][n+1]=(dp1[v][n+1]+dp1[u][n+1])%mod1;
			dp2[v][n+1]=(dp2[v][n+1]+dp2[u][n+1])%mod2;
		}
	}
	int g=q[n];
	for(int i=n+1;i>=0;i--)
	{
		if(dp[g][i]>0||i==0)
		{
			printf("%d\n",(dp[g][i]+i)%mod);
			break;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}
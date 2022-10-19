#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,mod,c[N][N],dp[N][N],s[N],d[N],pr[N],sf[N],ans[N],zz[N];
vector<int>e[N];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int u,int f)
{
	vector<int>p;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		p.push_back(v);
	}
	int m=p.size();
	for(int i=0;i<=n;i++)
		s[i]=d[i]=0;
	if(u==1)
	{
		for(int t=0;t<=n;t++)
		{
			int c=1;
			for(int i=0;i<m;i++)
			{
				s[i]=(s[i]+dp[p[i]][t])%mod;
				c=1ll*c*s[i]%mod;
			}
			ans[t]=c;
		}
	}
	else
	{
		for(int t=0;t<=n;t++)
		{
			int cf=1,vpr=1,vsf=1;
			for(int i=0;i<m;i++)
				s[i]=(s[i]+dp[p[i]][t])%mod;
			for(int i=0;i<m;i++)
				vpr=1ll*vpr*s[i]%mod,pr[i]=vpr;
			for(int i=m-1;i>=0;i--)
				vsf=1ll*vsf*s[i]%mod,sf[i]=vsf;
			dp[u][t]=(dp[u][t]+vpr)%mod;
			for(int i=0;i<m;i++)
			{
				dp[u][t]=(dp[u][t]+1ll*dp[p[i]][t]*d[i]%mod)%mod;
				int cl=(i<1?1:pr[i-1]),cr=(i<m-1?sf[i+1]:1);
				d[i]=(d[i]+1ll*cl*cr%mod)%mod;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	dfs(1,0);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(j&1)
				zz[i]=(zz[i]+mod-1ll*ans[i-j-1]*c[i][j]%mod)%mod;
			else
				zz[i]=(zz[i]+1ll*ans[i-j-1]*c[i][j]%mod)%mod;
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",zz[i]);
	return 0;
}
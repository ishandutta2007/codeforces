#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=13,mod=1e9+7;
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
struct solver
{
	int n,m,dp[N][M],fa[M],a[1<<M],b[1<<M];
	vector<int>e[N],g[M],z[M];
	void init(int _n,int _m){n=_n,m=_m;}
	void add1(int u,int v)
	{
		e[u].push_back(v);
		e[v].push_back(u);
	}
	void add2(int u,int v)
	{
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void dfs1(int u,int f)
	{
		fa[u]=f;
		z[u].clear();
		for(auto v:g[u])
			if(v!=f)
				dfs1(v,u),z[u].push_back(v);
	}
	void dfs2(int u,int f)
	{
		for(auto v:e[u])
		{
			if(v==f)
				continue;
			dfs2(v,u);
		}
		for(int i=1;i<=m;i++)
		{
			int t=(1<<z[i].size())-1;
			for(int s=0;s<=t;s++)
				a[s]=b[s]=0;
			a[0]=1;
			for(auto v:e[u])
			{
				if(v==f)
					continue;
				for(int s=0;s<=t;s++)
					b[s]=a[s];
				for(int s=0;s<=t;s++)
					for(int j=0;j<z[i].size();j++)
						if(!(s>>j&1))
							a[s|(1<<j)]=(a[s|(1<<j)]+1ll*b[s]*dp[v][z[i][j]]%mod)%mod;
			}
			dp[u][i]=a[t];
		}
	}
	int cal(int r)
	{
		dfs1(r,0);
		dfs2(1,0);
		int s=0;
		for(int i=1;i<=n;i++)
			s=(s+dp[i][r])%mod;
		return s;
	}
	int sol()
	{
		int s=0;
		for(int r=1;r<=m;r++)
			s=(s+cal(r))%mod;
		return s;
	}
}x,y;
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		x.add1(u,v);
	}
	scanf("%d",&m);
	for(int i=1;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		x.add2(u,v);
		y.add1(u,v);
		y.add2(u,v);
	}
	x.init(n,m);
	y.init(m,m);
	int f=x.sol();
	int g=y.sol();
	int ans=1ll*f*qp(g,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}
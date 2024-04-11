#include<bits/stdc++.h>
using namespace std;
const int N=55,inf=1e9;
int n,m,s,sz[N],d[N][N],g[N][N],dp[N][N][N][N],ans;
vector<int>e[N],tr[N][N];
void dfsp(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfsp(v,u);
		sz[u]+=sz[v];
	}
}
int dfs(int f,int u,int c,int t)
{
	int &r=dp[f][u][c][t];
	if(!t) return r=0;
	if(!c) return r=inf;
	if(r!=-1) return r;
	if(!tr[f][u].size()) return r=d[f][u]+dfs(u,f,t-c,t-c);
	for(auto v:tr[f][u])
		for(int i=0;i<=c;i++)
			dfs(u,v,i,t);
	for(int i=0;i<=tr[f][u].size();i++)
		for(int j=0;j<=c;j++)
			g[i][j]=0;
	g[0][0]=inf;
	for(int i=0;i<tr[f][u].size();i++)
		for(int j=0;j<=c;j++)
			for(int k=0;j+k<=c;k++)
				g[i+1][j+k]=max(g[i+1][j+k],min(g[i][j],dfs(u,tr[f][u][i],k,t)));
	return r=g[tr[f][u].size()][c]+d[f][u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=d[v][u]=w;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		for(auto u:e[i])
			for(auto v:e[i])
				if(u^v)
					tr[u][i].push_back(v);
	scanf("%d%d",&s,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		sz[x]++;
	}
	dfsp(s,0);
	ans=inf;
	memset(dp,-1,sizeof(dp));
	for(auto u:e[s])
		ans=min(ans,dfs(s,u,sz[u],m));
	printf("%d\n",ans);
	return 0;
}
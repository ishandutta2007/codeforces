#include <iostream>
#define int long long
using namespace std;
struct edge
{
	int v,n,w;
}e[500005];
int head[100005],cnt;
inline void add(int u,int v,int w)
{
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
int a[100005],dp[100005],vis[100005];
inline void dfs2(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].n)
	{
		if(!vis[e[i].v])
			dfs2(e[i].v);
	}
}
inline void dfs(int u)
{
	for(int i=head[u];i;i=e[i].n)
	{
		dp[e[i].v]=max((int)0,dp[u]+e[i].w);
		dfs(e[i].v);
	}
}
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<n;i++)
	{
		int f,w;
		cin >> f >> w;
		add(f,i+1,w);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(dp[i]>a[i])
		{
			dfs2(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=vis[i];
	cout << ans;
	return 0;
}
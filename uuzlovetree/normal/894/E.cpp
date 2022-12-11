#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int n,m,s;
vector< pair<int,int> > g[maxn],g2[maxn];
stack<int> stk;
vector<int> scc[maxn];
int pre[maxn],low[maxn],bel[maxn],Tim,cnt;
void tarjan(int u)
{
	pre[u]=low[u]=++Tim;
	stk.push(u);
	for(auto pa:g[u])
	{
		int v=pa.first;
		if(!pre[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!bel[v])low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u])
	{
		cnt++;
		while(1)
		{
			int x=stk.top();stk.pop();
			bel[x]=cnt;
			scc[cnt].push_back(x);
			if(x==u)break;
		} 
	}
}
ll calc(ll w)
{
	ll l=0,r=20000,t=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(mid*(mid+1)<=2*w)t=mid,l=mid+1;
		else r=mid-1;
	}
	return (t+1)*w-((t+1)*(t+1)*t/2-t*(t+1)*(2*t+1)/6);
}
ll we[maxn],dp[maxn];
void dfs(int u)
{
	if(dp[u])return;
	dp[u]=0;
	for(auto pa:g2[u])
	{
		int v=pa.first,w=pa.second;
		dfs(v);
		dp[u]=max(dp[u],dp[v]+w);
	}
	dp[u]+=we[u];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int u,v,w,i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
	}
	Tim=cnt=0;
	for(int i=1;i<=n;++i)if(!pre[i])tarjan(i);
	for(int u=1;u<=n;++u)
	{
		for(auto pa:g[u])
		{
			int v=pa.first,w=pa.second;
			if(bel[u]==bel[v])we[bel[u]]+=calc(w);
			else g2[bel[u]].push_back(make_pair(bel[v],w));
		}
	}
	scanf("%d",&s);
	dfs(bel[s]);
	printf("%lld\n",dp[bel[s]]);
}
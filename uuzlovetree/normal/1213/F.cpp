#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,k;
int p[maxn],q[maxn];
vector<int> g[maxn];
stack<int> stk;
vector<int> scc[maxn],g2[maxn];
int pre[maxn],low[maxn],bel[maxn],Tim,cnt;
void tarjan(int u)
{
	pre[u]=low[u]=++Tim;
	stk.push(u);
	for(int v:g[u])
	{
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
int dp[maxn];
void dfs(int u)
{
	if(dp[u])return;
	dp[u]=1;
	for(int v:g2[u])
	{
		dfs(v);
		dp[u]=max(dp[u],dp[v]+1);
	}
}
char Ans[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)scanf("%d",&q[i]);
	for(int i=1;i<n;++i)g[p[i]].push_back(p[i+1]);
	for(int i=1;i<n;++i)g[q[i]].push_back(q[i+1]);
	cnt=0;Tim=0;
	for(int i=1;i<=n;++i)if(!pre[i])tarjan(i);
	for(int i=1;i<n;++i)
	{
		if(bel[p[i]]!=bel[p[i+1]])g2[bel[p[i]]].push_back(bel[p[i+1]]);
		if(bel[q[i]]!=bel[q[i+1]])g2[bel[q[i]]].push_back(bel[q[i+1]]);
	}
	dfs(bel[p[1]]);
	if(dp[bel[p[1]]]<k)puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=cnt;++i)
		{
			int col=dp[i];
			if(col>k)col=k;
			for(int u:scc[i])Ans[u]='a'+26-col;
		}
	}
	printf("%s\n",Ans+1);
}
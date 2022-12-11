#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,m;
int head[maxn],p;
struct edge
{
	int to,next;
}e[maxn];
void addedge(int u,int v)
{
	e[++p].to=v;e[p].next=head[u];head[u]=p;
}
int d[maxn],ind[maxn];
ll dp[maxn];
ll ans;
queue<int> q;
void toposort()
{
	for(int i=1;i<=n;++i)dp[i]=1;
	for(int i=1;i<=n;++i)if(!ind[i])q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			dp[v]=max(dp[v],dp[u]+1);
			ind[v]--;
			if(!ind[v])q.push(v);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		d[u]++;d[v]++;
		ind[v]++;
		addedge(u,v);
	}
	toposort();
	for(int i=1;i<=n;++i)ans=max(ans,1ll*dp[i]*d[i]);
	printf("%I64d\n",ans);
	return 0;
}
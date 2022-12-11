#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,q;
struct edge
{
	int to,next;
}e[maxn<<1];
int head[maxn],p;
void addedge(int u,int v)
{
	e[++p].to=v;e[p].next=head[u];head[u]=p;
}
int d[maxn],anc[maxn][20],size[maxn];
void dfs(int u,int f)
{
	size[u]=1;
	d[u]=d[f]+1;anc[u][0]=f;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u);
		size[u]+=size[v];
	}
}
void predp()
{
	for(int j=1;j<=18;++j)
		for(int i=1;i<=n;++i)anc[i][j]=anc[anc[i][j-1]][j-1];
}
int lca(int u,int v)
{
	if(d[u]<d[v])swap(u,v);
	for(int i=18;i>=0;--i)if(d[anc[u][i]]>=d[v])u=anc[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
int getanc(int x,int k)
{
	for(int i=18;i>=0;--i)if(k>=(1<<i))x=anc[x][i],k-=(1<<i);
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	predp();
	scanf("%d",&q);
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int t=lca(u,v);
		int dis1=d[u]-d[t],dis2=d[v]-d[t];
		int ans;
		if(u==v)ans=n;
		else if(dis1==dis2)
		{
			int x=getanc(u,dis1-1);
			int y=getanc(v,dis2-1);
			ans=n-size[x]-size[y];
		}
		else
		{
			if((dis1+dis2)&1)ans=0;
			else
			{
				int D=(dis1+dis2)/2;
				if(d[u]<d[v])swap(u,v);
				int x=getanc(u,D);
				int y=getanc(u,D-1);
				ans=size[x]-size[y];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
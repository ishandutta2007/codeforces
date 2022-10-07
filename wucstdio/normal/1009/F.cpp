#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2000005];
int n,m,edgenum,head[1000005],pa[1000005],_f[5000005],*f[1000005],son[1000005],maxd[1000005],dep[1000005],tot;
int ans[1000005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		if(maxd[to]>maxd[son[node]])son[node]=to;
		maxd[node]=max(maxd[node],maxd[to]+1);
	}
}
void dfs2(int node,int st)
{
	f[node]=_f+st;
	tot=max(tot,st+maxd[node]+1);
	if(son[node])
	{
		dfs2(son[node],st+1);
		ans[node]=ans[son[node]]+1;
	}
	f[node][0]=1;
	if(f[node][ans[node]]<=f[node][0])ans[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		pa[to]=node;
		dfs2(to,tot);
		for(int i=0;i<=maxd[to];i++)
		{
			f[node][i+1]+=f[to][i];
			if(f[node][i+1]>f[node][ans[node]]||(f[node][i+1]==f[node][ans[node]]&&i+1<ans[node]))
			  ans[node]=i+1;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],dep[200005],pa[200005],size[200005],depx,x[200005],son[200005],maxd[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs_pre(int node)
{
	dep[node]=dep[pa[node]]+1;
	size[node]=1;
	maxd[node]=dep[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs_pre(to);
		maxd[node]=max(maxd[node],maxd[to]);
		size[node]+=size[to];
		if(size[to]>size[son[node]]&&maxd[to]>=depx)son[node]=to;
	}
}
void solve()
{
	int node=1;
	while(1)
	{
		if(dep[node]==depx)
		{
			printf("d %d\n",node);
			fflush(stdout);
			int d;
			scanf("%d",&d);
			if(d==0)
			{
				printf("! %d\n",node);
				fflush(stdout);
				exit(0);
			}
			node=x[dep[node]-d/2];
			printf("s %d\n",node);
			fflush(stdout);
			scanf("%d",&node);
			if(dep[node]==depx)
			{
				printf("! %d\n",node);
				fflush(stdout);
				return;
			}
		}
		x[dep[node]]=node;
		node=son[node];
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
	printf("d 1\n");
	fflush(stdout);
	scanf("%d",&depx);
	depx++;
	dfs_pre(1);
	solve();
	return 0;
}
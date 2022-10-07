#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[400005];
int n,m,edgenum,head[200005],pa[200005],size[200005],xu[200005],ti[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
int ind;
void dfs(int node)
{
	xu[++ind]=node;
	ti[node]=ind;
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	  scanf("%d",&pa[i]);
	for(int i=n;i>=2;i--)
	  add(pa[i],i);
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x,t;
		scanf("%d%d",&x,&t);
		if(size[x]<t)printf("-1\n");
		else printf("%d\n",xu[ti[x]+t-1]);
	}
	return 0;
}
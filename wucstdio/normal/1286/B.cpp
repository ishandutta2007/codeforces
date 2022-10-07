#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2005];
int n,r,edgenum,head[2005],pa[2005],size[2005],num[2005],a[2005],dfn[2005],pos[2005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void dfs(int node)
{
	dfn[node]=++ind;
	pos[ind]=node;
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs(to);
		size[node]+=size[to];
	}
	if(num[node]>=size[node])
	{
		printf("NO\n");
		exit(0);
	}
	a[node]=dfn[node]+num[node];
	for(int i=dfn[node]+1;i<=dfn[node]+size[node]-1;i++)
	{
		int v=pos[i];
		if(a[v]<=a[node])a[v]--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&pa[i],&num[i]);
		if(pa[i]==0)r=i;
		else add(pa[i],i);
	}
	dfs(r);
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],pa[200005],a[200005],cnt[200005],f[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(a[node]==0)cnt[node]--;
	else cnt[node]++;
	f[node]=cnt[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		cnt[node]+=cnt[to];
		f[node]+=max(0,f[to]);
	}
}
void dfs2(int node)
{
	if(node!=1)f[node]+=max(0,f[pa[node]]-max(0,f[node]));
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		dfs2(to);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	printf("\n");
	return 0;
}
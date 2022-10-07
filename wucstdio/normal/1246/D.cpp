#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],pa[100005],len[100005],son[100005],a[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		len[node]=max(len[node],len[to]+1);
		if(son[node]==0||len[to]>len[son[node]])son[node]=to;
	}
}
int now;
void dfs2(int node)
{
	printf("%d ",node);
	a[++now]=node;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		dfs2(to);
	}
	if(son[node])dfs2(son[node]);
}
void dfs3(int node)
{
	now++;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		dfs3(to);
	}
	if(son[node])dfs3(son[node]);
	if(now<n)printf("%d ",a[now+1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&pa[i]);
		add(pa[i],i);
	}
	dfs1(0);
	dfs2(0);
	printf("\n");
	printf("%d\n",n-len[0]-1);
	now=0;
	dfs3(0);
	return 0;
}
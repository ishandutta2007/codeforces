#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[200005];
int n,m,d,edgenum,head[100005],max1[100005],max2[100005],up[100005],dep[100005],pa[100005],ans;
bool flag[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		if(flag[to]&&max1[to]==0)
		{
			if(max1[node]==0)max1[node]=1;
			else if(max2[node]==0)max2[node]=1;
		}
		if(max1[to]==0)continue;
		if(max1[to]+1>max1[node])
		{
			max2[node]=max1[node];
			max1[node]=max1[to]+1;
		}
		else if(max1[to]+1>max2[node])max2[node]=max1[to]+1;
	}
}
void dfs2(int node)
{
	if(node!=1)
	{
		if(up[pa[node]]!=0)up[node]=max(up[node],up[pa[node]]+1);
		else if(flag[pa[node]])up[node]=max(up[node],1);
		if(max1[node]+1==max1[pa[node]]&&max2[pa[node]]!=0)up[node]=max(up[node],max2[pa[node]]+1);
		else if(max1[node]+1!=max1[pa[node]])up[node]=max(up[node],max1[pa[node]]+1);
	}
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		dfs2(to);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		flag[x]=1;
	}
	if(d==0)
	{
		if(m==1)printf("1\n");
		else printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	dfs2(1);
//	for(int i=1;i<=n;i++)
//	  printf("%d ",max1[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)
//	  printf("%d ",max2[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)
//	  printf("%d ",up[i]);
//	printf("\n");
	for(int i=1;i<=n;i++)
	  if(up[i]<=d&&max1[i]<=d)
		ans++;
	printf("%d\n",ans);
	return 0;
}
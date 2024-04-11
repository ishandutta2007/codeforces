#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[200005];
struct Data
{
	int x;
	int size;
}a[1005];
int n,m,edgenum,head[1005],dep[1005],pa[1005],size[1005],maxx[1005],root,top,in[1005],dfn[1005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void dfs(int node)
{
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
		maxx[node]=max(maxx[node],size[to]);
	}
	maxx[node]=max(maxx[node],n-size[node]);
	if(maxx[node]<maxx[root])root=node;
}
int tot;
void dfs2(int node)
{
	dfn[node]=++ind;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs2(to);
		e[hd].len=(dfn[to]-dfn[node])*tot;
	}
}
bool cmp(Data a,Data b)
{
	return a.size>b.size;
}
int main()
{
	maxx[0]=2147483344;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	pa[root]=0;
	dfs(root);
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		a[++top].x=e[hd].to;
		a[top].size=size[e[hd].to];
	}
	sort(a+1,a+top+1,cmp);
	int s1=0,s2=0;
	for(int i=1;i<=top;i++)
	{
		if(s1<s2)in[a[i].x]=1,s1+=a[i].size;
		else in[a[i].x]=2,s2+=a[i].size;
	}
	tot=1;
	int xx=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(in[to]==2)continue;
		if(in[to]==1)dfs2(to);
		e[hd].len=dfn[to];
		xx+=size[to];
	}
	tot=xx+1;
	ind=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(in[to]==1)continue;
		if(in[to]==2)dfs2(to);
		e[hd].len=dfn[to]*tot;
		xx+=size[to];
	}
	for(int i=1;i<=edgenum;i+=2)
	{
		printf("%d %d %d\n",e[i].to,e[i+1].to,max(e[i].len,e[i+1].len));
	}
	return 0;
}
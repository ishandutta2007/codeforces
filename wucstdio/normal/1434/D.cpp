#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[1000005];
int n,m,edgenum=1,head[500005],pa[500005],dep[500005],s[500005];
int size1[500005],sizen[500005],dfn1[500005],dfnn[500005],pos[500005];
int x[500005],y[500005];
struct Tree
{
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((l+r)>>1)
	struct Node
	{
		int maxv[2];
		bool flag;
	}tree[2000005];
	void pushup(int x)
	{
		tree[x].maxv[0]=max(tree[lc].maxv[0],tree[rc].maxv[0]);
		tree[x].maxv[1]=max(tree[lc].maxv[1],tree[rc].maxv[1]);
	}
	void pushdown(int x)
	{
		if(tree[x].flag)
		{
			swap(tree[lc].maxv[0],tree[lc].maxv[1]);
			tree[lc].flag^=1;
			swap(tree[rc].maxv[0],tree[rc].maxv[1]);
			tree[rc].flag^=1;
			tree[x].flag=0;
		}
	}
	void debug(int x,int l,int r)
	{
		pushdown(x);
		if(l==r)printf("(%d %d) ",tree[x].maxv[0],tree[x].maxv[1]);
		else
		{
			debug(lc,l,mid);
			debug(rc,mid+1,r);
		}
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			tree[x].maxv[s[pos[l]]]=dep[pos[l]];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int from,int to)
	{
		if(l>=from&&r<=to)
		{
			swap(tree[x].maxv[0],tree[x].maxv[1]);
			tree[x].flag^=1;
			return;
		}
		pushdown(x);
		if(from<=mid)update(lc,l,mid,from,to);
		if(to>mid)update(rc,mid+1,r,from,to);
		pushup(x);
	}
	int ask()
	{
		return tree[1].maxv[0];
	}
	#undef lc
	#undef rc
	#undef mid
}T1,T2;
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void dfs(int node)
{
	dfnn[node]=++ind;
	pos[ind]=node;
	sizen[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		s[to]=s[node]^e[hd].len;
		dep[to]=dep[node]+1;
		y[hd>>1]=to;
		dfs(to);
		sizen[node]+=sizen[to];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	dfs(1);
	int u=0,v=0;
	for(int i=1;i<=n;i++)
		if(dep[i]>dep[u])u=i;
	memset(pa,0,sizeof(pa));
	memset(dep,0,sizeof(dep));
	memset(s,0,sizeof(s));
	memset(dfnn,0,sizeof(dfnn));
	memset(pos,0,sizeof(pos));
	memset(y,0,sizeof(y));
	ind=0;
	dfs(u);
	for(int i=1;i<=n;i++)
	  if(dep[i]>dep[v])v=i;
	for(int i=1;i<=n;i++)
	  dfn1[i]=dfnn[i],x[i]=y[i],size1[i]=sizen[i];
	T1.build(1,1,n);
	memset(pa,0,sizeof(pa));
	memset(dep,0,sizeof(dep));
	memset(s,0,sizeof(s));
	memset(dfnn,0,sizeof(dfnn));
	memset(pos,0,sizeof(pos));
	memset(y,0,sizeof(y));
	ind=0;
	dfs(v);
	T2.build(1,1,n);
//	for(int i=1;i<=n;i++)printf("%d ",dfn1[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",dfnn[i]);
//	printf("\n");
	scanf("%d",&m);
	while(m--)
	{
		int k;
		scanf("%d",&k);
		int v=x[k];
		T1.update(1,1,n,dfn1[v],dfn1[v]+size1[v]-1);
		v=y[k];
		T2.update(1,1,n,dfnn[v],dfnn[v]+sizen[v]-1);
		printf("%d\n",max(T1.ask(),T2.ask()));
//		T1.debug(1,1,n);
//		printf("\n");
//		T2.debug(1,1,n);
//		printf("\n");
	}
	return 0;
}
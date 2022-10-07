#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson tree[o].child[0]
#define rson tree[o].child[1]
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int child[2];
	ll sum;
	int maxv;
}tree[5000005];
struct Edge
{
	int to;
	int next;
}e[200005];
int n,edgenum,head[100005],pa[100005],tot,c[100005];
ll sum[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void pushup(int o)
{
	tree[o].maxv=max(tree[lson].maxv,tree[rson].maxv);
	tree[o].sum=0;
	if(tree[lson].maxv>=tree[rson].maxv)tree[o].sum+=tree[lson].sum;
	if(tree[rson].maxv>=tree[lson].maxv)tree[o].sum+=tree[rson].sum;
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y)return x+y;
	if(l==r)
	{
		tree[x].maxv+=tree[y].maxv;
		return x;
	}
	tree[x].child[0]=merge(tree[x].child[0],tree[y].child[0],l,mid);
	tree[x].child[1]=merge(tree[x].child[1],tree[y].child[1],mid+1,r);
	pushup(x);
	return x;
}
void add(int o,int l,int r,int p)
{
	if(l==r)
	{
		tree[o].maxv++;
		tree[o].sum=l;
		return;
	}
	if(p<=mid)
	{
		if(!lson)lson=++tot;
		add(lson,l,mid,p);
	}
	else
	{
		if(!rson)rson=++tot;
		add(rson,mid+1,r,p);
	}
	pushup(o);
}
void debug(int o,int l,int r)
{
	if(!o)return;
	printf("Node %d,[%d,%d]:lson=%d,rson=%d,maxx=%d,sum=%I64d\n",o,l,r,lson,rson,tree[o].maxv,tree[o].sum);
	debug(lson,l,mid);
	debug(rson,mid+1,r);
}
int dfs(int node)
{
	int root=++tot;
	add(root,1,n,c[node]);
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		int t=dfs(to);
		root=merge(root,t,1,n);
	}
	sum[node]=tree[root].sum;
	return root;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)printf("%I64d ",sum[i]);
	printf("\n");
	return 0;
}
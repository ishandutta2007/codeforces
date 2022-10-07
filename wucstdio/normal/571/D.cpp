#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct Tree
{
	ll add,sum;
	int clear,maxt;
}tree[2000005];
struct Edge
{
	int to;
	int nxt;
}e[1000005];
struct Query
{
	int type;
	int x,y;
}q[1000005];
struct Ask
{
	int id;
	int pos;
	int c;
	int time;
}a[1000005];
int n,m,edgenum,pa[1000005],head[1000005],size[1000005],dfn[1000005],tot,now[1000005],time[1000005];
ll ans[1000005];
bool cmp(Ask a,Ask b)
{
	return a.time<b.time;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int ind;
void dfs(int node)
{
	dfn[node]=2147483647;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
		dfn[node]=min(dfn[node],dfn[to]);
	}
	if(!size[node])
	{
		size[node]=1;
		dfn[node]=++ind;
	}
}
void pushup(int o)
{
	tree[o].sum=tree[lson].sum+tree[rson].sum;
	tree[o].maxt=max(tree[lson].maxt,tree[rson].maxt);
}
void pushdown(int o,int l,int r)
{
	if(tree[o].add)
	{
		tree[lson].add+=tree[o].add;
		tree[rson].add+=tree[o].add;
		tree[lson].sum+=tree[o].add*(mid-l+1);
		tree[rson].sum+=tree[o].add*(r-mid);
		tree[o].add=0;
	}
	if(tree[o].clear)
	{
		tree[lson].clear=max(tree[lson].clear,tree[o].clear);
		tree[rson].clear=max(tree[lson].clear,tree[o].clear);
		tree[lson].maxt=max(tree[lson].maxt,tree[o].clear);
		tree[rson].maxt=max(tree[rson].maxt,tree[o].clear);
		tree[o].clear=0;
	}
}
void add(int o,int l,int r,int from,int to,ll v)
{
	if(l>=from&&r<=to)
	{
		tree[o].add+=v;
		tree[o].sum+=v*(r-l+1);
		return;
	}
	pushdown(o,l,r);
	if(from<=mid)add(lson,l,mid,from,to,v);
	if(to>mid)add(rson,mid+1,r,from,to,v);
	pushup(o);
}
void clear(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].clear=max(tree[o].clear,v);
		tree[o].maxt=max(tree[o].maxt,v);
		return;
	}
	pushdown(o,l,r);
	if(from<=mid)clear(lson,l,mid,from,to,v);
	if(to>mid)clear(rson,mid+1,r,from,to,v);
	pushup(o);
}
ll ask1(int o,int l,int r,int p)
{
	if(l==r)return tree[o].sum;
	pushdown(o,l,r);
	if(p<=mid)return ask1(lson,l,mid,p);
	else return ask1(rson,mid+1,r,p);
}
int ask2(int o,int l,int r,int p)
{
	if(l==r)return tree[o].maxt;
	pushdown(o,l,r);
	if(p<=mid)return ask2(lson,l,mid,p);
	else return ask2(rson,mid+1,r,p);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int c=getchar();
		while(c!='U'&&c!='M'&&c!='A'&&c!='Z'&&c!='Q')c=getchar();
		if(c=='U')
		{
			q[i].type=1;
			scanf("%d%d",&q[i].x,&q[i].y);
		}
		if(c=='M')
		{
			q[i].type=2;
			scanf("%d%d",&q[i].x,&q[i].y);
		}
		if(c=='A')
		{
			q[i].type=3;
			scanf("%d",&q[i].x);
		}
		if(c=='Z')
		{
			q[i].type=4;
			scanf("%d",&q[i].x);
		}
		if(c=='Q')
		{
			q[i].type=5;
			scanf("%d",&q[i].x);
		}
	}
	for(int i=1;i<=2*n;i++)pa[i]=i;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		if(q[i].type!=2)continue;
		int u=find(q[i].x),v=find(q[i].y);
		pa[u]=pa[v]=++tot;
		add(tot,u);
		add(tot,v);
	}
	int r=++tot;
	for(int i=1;i<tot;i++)
	{
		if(find(i)==i)
		{
			pa[i]=r;
			add(r,i);
		}
	}
	pa[r]=0;
	dfs(r);
	for(int i=1;i<=n;i++)now[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(q[i].type==2)now[q[i].x]=pa[now[q[i].x]];
		if(q[i].type==4)clear(1,1,n,dfn[now[q[i].x]],dfn[now[q[i].x]]+size[now[q[i].x]]-1,i);
		if(q[i].type==5)time[i]=ask2(1,1,n,dfn[q[i].x]);
	}
	memset(head,0,sizeof(head));
	memset(pa,0,sizeof(pa));
	memset(dfn,0,sizeof(dfn));
	memset(size,0,sizeof(size));
	tot=n;
	edgenum=ind=0;
	for(int i=1;i<=2*n;i++)pa[i]=i;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		if(q[i].type!=1)continue;
		int u=find(q[i].x),v=find(q[i].y);
		pa[u]=pa[v]=++tot;
		add(tot,u);
		add(tot,v);
	}
	r=++tot;
	for(int i=1;i<tot;i++)
	{
		if(find(i)==i)
		{
			pa[i]=r;
			add(r,i);
		}
	}
	pa[r]=0;
	dfs(r);
	tot=0;
	for(int i=1;i<=n;i++)now[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(q[i].type==5)
		{
			a[++tot].c=-1;
			a[tot].pos=q[i].x;
			a[tot].id=i;
			a[tot].time=time[i];
			a[++tot].c=1;
			a[tot].pos=q[i].x;
			a[tot].id=i;
			a[tot].time=i;
		}
	}
	sort(a+1,a+tot+1,cmp);
	int nowa=1;
	while(nowa<=tot&&a[nowa].time==0)nowa++;
	for(int i=1;i<=m;i++)
	{
		if(q[i].type==1)now[q[i].x]=pa[now[q[i].x]];
		if(q[i].type==3)add(1,1,n,dfn[now[q[i].x]],dfn[now[q[i].x]]+size[now[q[i].x]]-1,size[now[q[i].x]]);
		while(nowa<=tot&&a[nowa].time==i)
		{
			ans[a[nowa].id]+=a[nowa].c*ask1(1,1,n,dfn[a[nowa].pos]);
			nowa++;
		}
	}
	for(int i=1;i<=m;i++)
	  if(q[i].type==5)
		printf("%lld\n",ans[i]);
	return 0;
}
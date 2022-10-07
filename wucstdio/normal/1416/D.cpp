#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Tree
{
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((l+r)>>1)
	int maxp[1600005],a[400005];
	void pushup(int x)
	{
		maxp[x]=a[maxp[lc]]>a[maxp[rc]]?maxp[lc]:maxp[rc];
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			maxp[x]=l;
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	int ask(int x,int l,int r,int from,int to)
	{
		if(l>=from&&r<=to)return maxp[x];
		int ans=from;
		if(from<=mid)
		{
			int p=ask(lc,l,mid,from,to);
			if(a[p]>=a[ans])ans=p;
		}
		if(to>mid)
		{
			int p=ask(rc,mid+1,r,from,to);
			if(a[p]>=a[ans])ans=p;
		}
		return ans;
	}
	void update(int x,int l,int r,int p)
	{
		if(l==r)
		{
			a[l]=0;
			return;
		}
		if(p<=mid)update(lc,l,mid,p);
		else update(rc,mid+1,r,p);
		pushup(x);
	}
}T;
struct Edge
{
	int u,v;
	int t;
}e[300005];
struct Query
{
	int type;
	int k;
}a[500005];
int n,m,q,tot,p[400005],t[400005],r[400005],pa[400005],anc[20][400005];
int child[400005][2];
bool cmp(Edge a,Edge b)
{
	return a.t>b.t;
}
int find(int x)
{
	return x==r[x]?x:r[x]=find(r[x]);
}
int ind,dfn[400005],size[400005];
void dfs(int node)
{
	dfn[node]=++ind;
	T.a[ind]=p[node];
	size[node]=1;
	if(child[node][0])dfs(child[node][0]);
	if(child[node][1])dfs(child[node][1]);
	size[node]+=size[child[node][0]]+size[child[node][1]];
}
void pre()
{
	for(int i=1;i<=tot;i++)anc[0][i]=pa[i];
	for(int i=1;i<20;i++)
	  for(int j=1;j<=tot;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
}
void ask(int node,int ti)
{
	for(int i=19;i>=0;i--)
	  if(t[anc[i][node]]>ti)
	    node=anc[i][node];
	int pos=T.ask(1,1,tot,dfn[node],dfn[node]+size[node]-1);
	printf("%d\n",T.a[pos]);
	T.update(1,1,tot,pos);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].u,&e[i].v),e[i].t=q+1;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a[i].type,&a[i].k);
		if(a[i].type==2)e[a[i].k].t=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)r[i]=i,t[i]=q+1;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue;
		pa[find(u)]=pa[find(v)]=++tot;
		child[tot][0]=find(u);
		child[tot][1]=find(v);
		r[tot]=r[find(u)]=r[find(v)]=tot;
		t[tot]=e[i].t;
	}
	for(int i=tot;i>=1;i--)
		if(!dfn[i])dfs(i);
	pre();
	T.build(1,1,tot);
	for(int i=1;i<=q;i++)
	{
		if(a[i].type==1)
		  ask(a[i].k,i);
	}
	return 0;
}
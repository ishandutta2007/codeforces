#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int max_n=1e5+5;
const int max_m=1e5+5;
const int max_tot=2e5+5;
int End[max_tot<<1],Last[max_tot],Next[max_tot<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int dfn[max_tot],low[max_n],Time; // 'dfn' and 'Time' will also be used in the block forest
int st[max_n],tp,u[max_tot],v[max_tot],tot,E;
void tarjan(int x) // block forest
{
	dfn[x]=low[x]=++Time;
	st[++tp]=x;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!dfn[y])
		{
			tarjan(y);
			if(low[y]==dfn[x])
			{
				++tot;
				do
				{
					u[++E]=tot,v[E]=st[tp--];
				}while(st[tp+1]!=y);
				u[++E]=tot,v[E]=x;
			}
			else
				low[x]=min(low[x],low[y]);
		}
		else
			low[x]=min(low[x],dfn[y]);
	}
}
int w[max_n],fath[max_tot];
multiset<int> S[max_tot]; // S[i]: the multiset of values of i's sons (i>n)
void dfs(int x,int fa)
{
	fath[x]=fa;
	if(x<=n) // x is an original node
	{
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(y!=fa)
				dfs(y,x);
		}
	}
	else
	{
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(y!=fa)
			{
				dfs(y,x);
				S[x].insert(w[y]);
			}
		}
	}
}
int siz[max_tot],son[max_tot],dep[max_tot];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	siz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])
				son[x]=y;
		}
	}
}
int top[max_tot],old[max_tot];
void dfs2(int x,int top_now)
{
	top[x]=top_now;
	dfn[x]=++Time;
	old[Time]=x;
	if(son[x])
	{
		dfs2(son[x],top_now);
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(y!=son[x]&&y!=fath[x])
				dfs2(y,y);
		}
	}
}
const int inf=1e9;
inline int W(int x)
{
	return x<=n?w[x]:*S[x].begin();
}
namespace SegTree
{
	int val[max_tot<<2];
	#define ls(p) ((p)<<1)
	#define rs(p) ((p)<<1|1)
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			val[p]=W(old[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		val[p]=min(val[ls(p)],val[rs(p)]);
	}
	void modify(int p,int l,int r,int k)
	{
		if(l==r)
		{
			val[p]=W(old[l]);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(ls(p),l,mid,k);
		else
			modify(rs(p),mid+1,r,k);
		val[p]=min(val[ls(p)],val[rs(p)]);
	}
	int res;
	void query(int p,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)
		{
			res=min(res,val[p]);
			return;
		}
		int mid=(l+r)>>1;
		if(a<=mid)
			query(ls(p),l,mid,a,b);
		if(b>mid)
			query(rs(p),mid+1,r,a,b);
	}
	inline int query(int a,int b)
	{
		res=inf;
		query(1,1,tot,a,b);
		return res;
	}
}
inline void query(int x,int y)
{
	int res=inf;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		res=min(res,SegTree::query(dfn[top[x]],dfn[x]));
		x=fath[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	res=min(res,SegTree::query(dfn[x],dfn[y]));
	if(x>n)
		res=min(res,w[fath[x]]);
	printf("%d\n",res);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",w+i);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	tot=n;
	tarjan(1); // There is always at least one valid route between any two cities.
	assert(tot<=2*n);
	for(int i=1;i<=n;++i)
		Last[i]=0;
	e=0;
	for(int i=1;i<=E;++i)
		add_edge(u[i],v[i]);
	dfs(1,0);
	dfs1(1,0);
	Time=0;
	dfs2(1,1);
	SegTree::build(1,1,tot);
	while(q--)
	{
		char opt[5];
		int a,b;
		scanf("%s%d%d",opt,&a,&b);
		if(opt[0]=='C')
		{
			int fa=fath[a];
			if(fa)
			{
				S[fa].erase(S[fa].find(w[a]));
				S[fa].insert(b);
				SegTree::modify(1,1,tot,dfn[fa]);
			}
			w[a]=b;
			SegTree::modify(1,1,tot,dfn[a]);
		}
		else
			query(a,b);
	}
	return 0;
}
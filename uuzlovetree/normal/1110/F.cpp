#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
using namespace std;
const ll inf = (ll)1e17;
int n,q;
int fa[maxn];
ll ww[maxn];
struct edge
{
	int to,next;
	ll w;
}e[maxn];
int head[maxn],p;
void addedge(int u,int v,ll w)
{
	e[++p].to=v;e[p].w=w;e[p].next=head[u];head[u]=p;
}
struct Query
{
	int v,l,r,id;
	Query(){};
	Query(int V,int L,int R,int ID){v=V;l=L;r=R;id=ID;} 
};
ll Ans[maxn];
vector<Query> Q[maxn];
struct Segmenttree
{
	ll minv[maxn<<2],addv[maxn<<2];
	void pushup(int rt)
	{
		minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
	}
	void pushdown(int rt)
	{
		if(addv[rt])
		{
			ll t=addv[rt];
			minv[rt<<1]+=t;minv[rt<<1|1]+=t;
			addv[rt<<1]+=t;addv[rt<<1|1]+=t;
			addv[rt]=0;
		}
	}
	void update(int rt,int l,int r,int pos,ll w)
	{
		int mid=(l+r)>>1;
		if(l==r)
		{
			addv[rt]=0;minv[rt]=w;
			return;
		}
		if(pos<=mid)update(rt<<1,l,mid,pos,w);
		else update(rt<<1|1,mid+1,r,pos,w);
		pushup(rt);
	}
	void add(int rt,int l,int r,int ql,int qr,ll w)
	{
		if(ql>qr)return;
		int mid=(l+r)>>1;
		if(ql<=l&&r<=qr)
		{
			addv[rt]+=w;minv[rt]+=w;
			return;
		}
		pushdown(rt);
		if(ql<=mid)add(rt<<1,l,mid,ql,qr,w);
		if(qr>mid)add(rt<<1|1,mid+1,r,ql,qr,w);
		pushup(rt);
	}
	ll query(int rt,int l,int r,int ql,int qr)
	{
		ll ans=inf;
		int mid=(l+r)>>1;
		if(ql<=l&&r<=qr)return minv[rt];
		pushdown(rt);
		if(ql<=mid)ans=min(ans,query(rt<<1,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,query(rt<<1|1,mid+1,r,ql,qr));
		pushup(rt);
		return ans;
	}
}sgt;
int size[maxn],lpos[maxn],rpos[maxn],cnt;
ll dis[maxn];
void dfs(int u)
{
	size[u]=1;
	lpos[u]=++cnt;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;ll w=e[i].w;
		dis[v]=dis[u]+w;
		dfs(v);
		size[u]+=size[v];
	}
	rpos[u]=cnt;
	if(size[u]==1)sgt.update(1,1,n,lpos[u],dis[u]);
	else sgt.update(1,1,n,lpos[u],inf);
}
void dfs2(int u)
{
	for(int i=0;i<Q[u].size();++i)
	{
		int id=Q[u][i].id,l=Q[u][i].l,r=Q[u][i].r;
		Ans[id]=sgt.query(1,1,n,l,r);
	}
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;ll w=e[i].w;
		sgt.add(1,1,n,lpos[v],rpos[v],-w);
		sgt.add(1,1,n,1,lpos[v]-1,w);
		sgt.add(1,1,n,rpos[v]+1,n,w);
		dfs2(v);
		sgt.add(1,1,n,lpos[v],rpos[v],w);
		sgt.add(1,1,n,1,lpos[v]-1,-w);
		sgt.add(1,1,n,rpos[v]+1,n,-w);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;++i)
	{
		int x;ll w;
		scanf("%d%I64d",&x,&w);
		fa[i]=x;ww[i]=w;
	}
	for(int i=n;i>=2;--i)addedge(fa[i],i,ww[i]);
	for(int i=1;i<=q;++i)
	{
		int v,l,r;
		scanf("%d%d%d",&v,&l,&r);
		Q[v].push_back(Query(v,l,r,i));
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=q;++i)printf("%I64d\n",Ans[i]);
	return 0;
}
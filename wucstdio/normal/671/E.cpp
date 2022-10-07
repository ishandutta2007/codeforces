#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct Tree
{
	ll suf;
	ll minp;
	int pos;
	ll addp,adds;
	pair<ll,int>res;
}tree[400005];
struct Edge
{
	int to;
	int nxt;
}e[100005];
int n,k,edgenum,nxt[100005],head[100005],maxp[100005],st[100005],top,ans;
ll w[100005],g[100005],pre[100005],suf[100005];
void pushdown(int x)
{
	if(tree[x].addp)
	{
		tree[lc].addp+=tree[x].addp;
		tree[rc].addp+=tree[x].addp;
		tree[lc].minp+=tree[x].addp;
		tree[rc].minp+=tree[x].addp;
		tree[lc].res.first+=tree[x].addp;
		tree[rc].res.first+=tree[x].addp;
		tree[x].addp=0;
	}
	if(tree[x].adds)
	{
		tree[lc].adds+=tree[x].adds;
		tree[rc].adds+=tree[x].adds;
		tree[lc].suf+=tree[x].adds;
		tree[rc].suf+=tree[x].adds;
		tree[lc].minp+=tree[x].adds;
		tree[rc].minp+=tree[x].adds;
		tree[x].adds=0;
	}
}
void _debug(int x,int l,int r)
{
	printf("%d [%d,%d]:",x,l,r);
	printf("suf=%lld,minp=%lld,pos=%d,res=(%lld,%d)\n",tree[x].suf,tree[x].minp,tree[x].pos,tree[x].res.first,tree[x].res.second);
	if(l==r)return;
	pushdown(x);
	_debug(lc,l,mid);
	_debug(rc,mid+1,r);
}
pair<ll,int>calc(int x,int l,int r,ll val)
{
	if(l==r)return make_pair(tree[x].minp-min(val,tree[x].suf),l);
	pushdown(x);
	pair<ll,int>ansl,ansr;
	if(val<tree[lc].minp)
	{
		ansl=make_pair(tree[lc].minp-val,tree[lc].pos);
		ansr=calc(rc,mid+1,r,val);
	}
	else
	{
		ansl=calc(lc,l,mid,val);
		ansr=tree[x].res;
	}
	return min(ansl,ansr);
}
void pushup(int x,int l,int r)
{
	tree[x].minp=min(tree[lc].minp,tree[rc].minp);
	tree[x].pos=tree[lc].minp<tree[rc].minp?tree[lc].pos:tree[rc].pos;
	tree[x].suf=min(tree[lc].suf,tree[rc].suf);
	tree[x].res=calc(rc,mid+1,r,tree[lc].suf);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		tree[x].minp=suf[l];
		tree[x].suf=suf[l];
		tree[x].pos=l;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x,l,r);
}
void addp(int x,int l,int r,int from,int to,ll v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[x].addp+=v;
		tree[x].minp+=v;
		tree[x].res.first+=v;
		return;
	}
	pushdown(x);
	if(from<=mid)addp(lc,l,mid,from,to,v);
	if(to>mid)addp(rc,mid+1,r,from,to,v);
	pushup(x,l,r);
}
void adds(int x,int l,int r,int from,int to,ll v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		tree[x].adds+=v;
		tree[x].suf+=v;
		tree[x].minp+=v;
		return;
	}
	pushdown(x);
	if(from<=mid)adds(lc,l,mid,from,to,v);
	if(to>mid)adds(rc,mid+1,r,from,to,v);
	pushup(x,l,r);
}
ll ask(int x,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[x].suf;
	ll ans=1e18;
	pushdown(x);
	if(from<=mid)ans=min(ans,ask(lc,l,mid,from,to));
	if(to>mid)ans=min(ans,ask(rc,mid+1,r,from,to));
	return ans;
}
int query(int x,int l,int r,int from,int to,ll&val)
{
	if(l==r)
	{
		val=min(val,tree[x].suf);
		return k>=tree[x].minp-val?l:0;
	}
	pushdown(x);
	if(l>=from&&r<=to)
	{
		if(k>=calc(rc,mid+1,r,min(val,tree[lc].suf)).first)
		{
			val=min(val,tree[lc].suf);
			return query(rc,mid+1,r,from,to,val);
		}
		else if(k>=calc(lc,l,mid,val).first)
		{
			int ans=query(lc,l,mid,from,to,val);
			val=min(val,tree[rc].suf);
			return ans;
		}
		else return 0;
	}
	if(from>mid)return query(rc,mid+1,r,from,to,val);
	if(to<=mid)return query(lc,l,mid,from,to,val);
	ll left=ask(lc,l,mid,from,mid);
	ll v=min(val,left);
	int ans=query(rc,mid+1,r,from,to,v);
	if(ans)return ans;
	return query(lc,l,mid,from,to,val);
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	st[++top]=node;
//	printf("%d %d\n",node,nxt[node]);
	if(nxt[node]&&nxt[node]!=n+1)
	{
		addp(1,1,n,nxt[node]-1,n,pre[node]-pre[nxt[node]]);
		adds(1,1,n,1,nxt[node]-2,pre[node]-pre[nxt[node]]);
	}
	maxp[node]=maxp[nxt[node]];
	if(!nxt[node])maxp[node]=top;
	while(pre[node]-pre[st[maxp[node]]]>k)maxp[node]++;
	if(node<=n)
	{
		addp(1,1,n,st[maxp[node]-1]-1,st[maxp[node]-1]-1,pre[st[maxp[node]-1]]-pre[st[maxp[node]]]);
		adds(1,1,n,st[maxp[node]-1]-1,st[maxp[node]-1]-1,pre[st[maxp[node]]]-pre[st[maxp[node]-1]]);
	}
//	printf("[%d,%d]\n",node,st[maxp[node]-1]-1);
//	_debug(1,1,n);
	ll tmp=1e18;
	if(nxt[node])ans=max(ans,query(1,1,n,node,st[maxp[node]-1]-1,tmp)-node+1);
	if(node<=n)
	{
		addp(1,1,n,st[maxp[node]-1]-1,st[maxp[node]-1]-1,pre[st[maxp[node]]]-pre[st[maxp[node]-1]]);
		adds(1,1,n,st[maxp[node]-1]-1,st[maxp[node]-1]-1,pre[st[maxp[node]-1]]-pre[st[maxp[node]]]);
	}
//	printf("%d\n",ans);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs(to);
	}
	top--;
	if(nxt[node]&&nxt[node]!=n+1)
	{
		addp(1,1,n,nxt[node]-1,n,pre[nxt[node]]-pre[node]);
		adds(1,1,n,1,nxt[node]-2,pre[nxt[node]]-pre[node]);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&g[i]);
	for(int i=2;i<=n;i++)pre[i]=pre[i-1]+g[i-1]-w[i-1];
	for(int i=n-1;i>=1;i--)suf[i]=suf[i+1]+g[i+1]-w[i];
	pre[n+1]=-1e18;
	build(1,1,n);
	for(int i=n+1;i>=1;i--)
	{
		while(top&&pre[st[top]]>=pre[i])top--;
		nxt[i]=st[top];
		if(top)add(st[top],i);
		st[++top]=i;
	}
	top=0;
	dfs(n+1);
	printf("%d\n",ans);
	return 0;
}
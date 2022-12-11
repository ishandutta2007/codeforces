#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,q,ID[maxn];
int head[maxn],p;
struct edge
{
	int to,next,w;
	int id;
}e[maxn<<1];
void addedge(int u,int v,int w,int id)
{
	e[++p].to=v;e[p].w=w;e[p].id=id;e[p].next=head[u];head[u]=p;
	e[++p].to=u;e[p].w=w;e[p].id=id;e[p].next=head[v];head[v]=p;
}
int d[maxn],rt;
void dfs(int u,int f)
{
	d[u]=d[f]+1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f)continue;
		dfs(v,u);
	}
}
int bel[maxn],w[maxn];
int lpos[maxn],rpos[maxn],cnt,tpos[maxn];
void dfs2(int u,int f,int id)
{
	d[u]=d[f]+1;lpos[u]=++cnt;tpos[cnt]=u;
	bel[id]=u;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f)continue;
		if(e[i].w)w[v]=w[u]+1;
		else w[v]=w[u];
		dfs2(v,u,e[i].id);
	}
	rpos[u]=cnt;
}
int Ans[maxn];
int v0[maxn<<2],v1[maxn<<2],rev[maxn<<2];
void pushup(int rt)
{
	v0[rt]=max(v0[rt<<1],v0[rt<<1|1]);
	v1[rt]=max(v1[rt<<1],v1[rt<<1|1]);
}
void pushdown(int rt)
{
	if(rev[rt])
	{
		swap(v0[rt<<1],v1[rt<<1]);
		swap(v0[rt<<1|1],v1[rt<<1|1]);
		rev[rt<<1]^=1;rev[rt<<1|1]^=1;
		rev[rt]=0;
	}
}
void build(int rt,int l,int r)
{
	rev[rt]=0;
	if(l==r)
	{
		if(w[tpos[l]]&1)v1[rt]=d[tpos[l]]-1,v0[rt]=0;
		else v0[rt]=d[tpos[l]]-1,v1[rt]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void change(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		swap(v0[rt],v1[rt]);
		rev[rt]^=1;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(ql<=mid)change(rt<<1,l,mid,ql,qr);
	if(qr>mid)change(rt<<1|1,mid+1,r,ql,qr);
	pushup(rt); 
}
int query(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return v0[rt];
	int ans=0,mid=(l+r)>>1;
	pushdown(rt);
	if(ql<=mid)ans=max(ans,query(rt<<1,l,mid,ql,qr));
	if(qr>mid)ans=max(ans,query(rt<<1|1,mid+1,r,ql,qr));
	pushup(rt); 
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w,i);
	}
	dfs(1,0);
	int pos=0;
	for(int i=1;i<=n;++i)if(d[i]>d[pos])pos=i;
	memset(d,0,sizeof(d));
	dfs(pos,0);
	for(int i=1;i<=n;++i)if(d[i]>d[rt])rt=i;
	memset(d,0,sizeof(d));
	dfs2(rt,0,0);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&ID[i]);
		change(1,1,n,lpos[bel[ID[i]]],rpos[bel[ID[i]]]);
		Ans[i]=query(1,1,n,1,n);
	}
	for(int i=1;i<=n;++i)if(d[i]>d[rt])rt=i;
	memset(d,0,sizeof(d));
	memset(bel,0,sizeof(bel));
	memset(w,0,sizeof(w));
	memset(lpos,0,sizeof(lpos));
	memset(rpos,0,sizeof(rpos));
	memset(tpos,0,sizeof(tpos));
	cnt=0;
	dfs2(rt,0,0);
	build(1,1,n);
	for(int i=1;i<=q;++i)
	{
		change(1,1,n,lpos[bel[ID[i]]],rpos[bel[ID[i]]]);
		Ans[i]=max(Ans[i],query(1,1,n,1,n));
	}
	for(int i=1;i<=q;++i)printf("%d\n",Ans[i]);
}
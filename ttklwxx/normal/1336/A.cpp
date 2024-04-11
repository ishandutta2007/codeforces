#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct bbian
{
	int u,v,nex;
}b[800004];
int head[300001],tmp;
void addb(int x,int y)
{
	b[++tmp].u=x;
	b[tmp].v=y;
	b[tmp].nex=head[x];
	head[x]=tmp;
} 
struct tree
{
	int l,r,maxn,mpos,laz;
}a[800004];
int wt[300001];
inline void pushup(int k)
{
	a[k].maxn=max(a[k<<1].maxn,a[k<<1|1].maxn);
	if(a[k<<1].maxn>=a[k<<1|1].maxn)a[k].mpos=a[k<<1].mpos;
	else a[k].mpos=a[k<<1|1].mpos;
}
inline void pushdown(int k)
{
	a[k<<1].maxn-=a[k].laz;
	a[k<<1].laz+=a[k].laz;
	a[k<<1|1].maxn-=a[k].laz;
	a[k<<1|1].laz+=a[k].laz;
	a[k].laz=0;
}
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].laz=0;
	if(l==r)
	{
		a[k].maxn=wt[l];
		a[k].mpos=l;
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	pushup(k);
	return;
}
void change(int l,int r,int k)
{
	if(a[k].l>r||a[k].r<l)return;
	if(a[k].l>=l&&a[k].r<=r)
	{
		a[k].laz++;
		a[k].maxn--;
		return;
	}
	pushdown(k);
	change(l,r,k<<1);
	change(l,r,k<<1|1);
	pushup(k);
}
int query(int x,int k)
{
	if(a[k].l==a[k].r)
	{
	    return a[k].maxn;
	}
	pushdown(k);
	if(x<=a[k<<1].r)return query(x,k<<1);
	else return query(x,k<<1|1);
}
void changes(int x,int k)
{
	if(a[k].l==a[k].r)
	{
	    a[k].maxn=-100000000;
	    return;
	}
	pushdown(k);
	if(x<=a[k<<1].r)changes(x,k<<1);
	else changes(x,k<<1|1);
	pushup(k);
}
int fa[300001],siz[300001],son[300001],dep[300001];
void dfs1(int x,int f)
{
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	int maxn=-1;
	for(int i=head[x];i;i=b[i].nex)
	{
		if(b[i].v==f)continue;
		dfs1(b[i].v,x);
		siz[x]+=siz[b[i].v];
		if(siz[b[i].v]>maxn)
		{
			maxn=siz[b[i].v];
			son[x]=b[i].v;
		}
	}
}
int top[300001],cnt,nid[300001],fx[300001];
void dfs2(int x,int ttop)
{
	top[x]=ttop;
	nid[x]=++cnt;
	wt[cnt]=dep[x]-1;
	fx[cnt]=x;
	if(son[x]==0)return;
	dfs2(son[x],ttop);
	for(int i=head[x];i;i=b[i].nex)
	{
		if(b[i].v==fa[x]||b[i].v==son[x])continue;
		dfs2(b[i].v,b[i].v);
	}
}
void changeb(int x)
{
	while(x!=0)
	{
		change(nid[top[x]],nid[x],1);
		x=fa[top[x]];
	}
}
signed main()
{
	int n,k,x,y;
	n=read();
	k=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		addb(x,y);
		addb(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		x=a[1].mpos;
		ans+=query(x,1);
		changeb(fx[x]);
		changes(x,1);
	}
	printf("%lld\n",ans);
	return 0;
	
}
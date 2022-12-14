#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 200005
#define ll long long
namespace Segment_Tree
{
	#define lson l,m,rt<<1
	#define rson m+1,r,rt<<1|1
	int mn[N<<2],sn[N<<2],tag[N<<2];
	inline void PushUp(int rt)
	{
		if(mn[rt<<1]<mn[rt<<1|1])mn[rt]=mn[rt<<1],sn[rt]=sn[rt<<1];
		else if(mn[rt<<1|1]<mn[rt<<1])mn[rt]=mn[rt<<1|1],sn[rt]=sn[rt<<1|1];
		else mn[rt]=mn[rt<<1],sn[rt]=sn[rt<<1]+sn[rt<<1|1];
	}
	inline void giv(int rt,int v){mn[rt]+=v,tag[rt]+=v;}
	inline void PushDown(int rt){if(tag[rt])giv(rt<<1,tag[rt]),giv(rt<<1|1,tag[rt]),tag[rt]=0;}
	void Update(int L,int R,int v,int l,int r,int rt)
	{
		if(L<=l&&r<=R)return giv(rt,v);PushDown(rt);int m=(l+r)>>1;
		if(L<=m)Update(L,R,v,lson);if(m<R)Update(L,R,v,rson);PushUp(rt);
	}
	int query(int L,int R,int l,int r,int rt)
	{
		if(L<=l&&r<=R)return mn[rt]==1?sn[rt]:0;PushDown(rt);int m=(l+r)>>1,ret=0;
		if(L<=m)ret=query(L,R,lson);if(m<R)ret+=query(L,R,rson);return ret;
	}
	void build(int l,int r,int rt){sn[rt]=r-l+1;if(l==r)return ;int m=(l+r)>>1;build(lson),build(rson);}
}
namespace LCT
{
	#define ls ch[rt][0]
	#define rs ch[rt][1]
	#define get(rt) (ch[f[rt]][0]!=rt)
	#define isroot(rt) (ch[f[rt]][0]!=rt&&ch[f[rt]][1]!=rt)
	int ch[N][2],f[N],rev[N];
	inline void giv(int rt){swap(ls,rs);rev[rt]^=1;}
	inline void PushDown(int rt){if(rev[rt])giv(ls),giv(rs),rev[rt]=0;}
	inline void rotate(int rt)
	{
		int x=f[rt],y=f[x],k=get(rt);
		if(!isroot(x))ch[y][ch[y][0]!=x]=rt;
		ch[x][k]=ch[rt][!k],f[ch[x][k]]=x;
		ch[rt][!k]=x,f[x]=rt,f[rt]=y;
	}
	void Update(int rt){if(!isroot(rt))Update(f[rt]);PushDown(rt);}
	inline void Splay(int rt)
	{
		for(Update(rt);!isroot(rt);rotate(rt))
			if(!isroot(f[rt]))rotate(get(rt)==get(f[rt])?f[rt]:rt);
	}
	inline void access(int rt){for(int t=0;rt;t=rt,rt=f[rt])Splay(rt),rs=t;}
	inline void make_root(int rt){access(rt),Splay(rt),giv(rt);}
	inline void Link(int rt,int x){make_root(rt);f[rt]=x;}
	inline void cut(int rt,int x){make_root(x),access(rt),Splay(rt);ls=f[x]=0;}
	inline int find(int rt){access(rt);Splay(rt);while(ls)rt=ls;return Splay(rt),rt;}
	inline bool check(int x,int y){return find(x)==find(y);}
}
int a[1005][1005],n,m,now;
int px[N],py[N],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
inline void cut(int L,int R,int u)
{
	int x=px[u],y=py[u];
	for(int k=0,tx,ty;k<4;k++)
	{
		tx=x+dx[k],ty=y+dy[k];if(tx>n||tx<1||ty>m||ty<1)continue;
		if(L<=a[tx][ty]&&a[tx][ty]<=R-1)LCT::cut(u,a[tx][ty]);
	}
}
inline void work(int R,int x,int y)
{
	while(now<=y&&LCT::check(x,y))cut(now+1,R,now),now++;
	if(now<=y)LCT::Link(x,y),Segment_Tree::Update(1,y,-1,1,n*m,1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),px[a[i][j]]=i,py[a[i][j]]=j;
	now=1;ll ans=0;Segment_Tree::build(1,n*m,1);
	for(int i=1;i<=n*m;i++)
	{
		int x=px[i],y=py[i];
		for(int k=0,tx,ty;k<4;k++)
		{
			tx=x+dx[k],ty=y+dy[k];if(tx>n||tx<1||ty>m||ty<1)continue;
			if(now<=a[tx][ty]&&a[tx][ty]<=i)work(i,i,a[tx][ty]);
		}
		Segment_Tree::Update(1,i,1,1,n*m,1);
		ans+=Segment_Tree::query(now,i,1,n*m,1);
	}
	printf("%lld\n",ans);
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 500005
#define ll long long
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
struct Segment{int ls,rs;ll mn,tag;}tr[N*30];
int rot[N],cnt;
void insert(int x,ll v,int l,int r,int &rt)
{
	if(!rt)rt=++cnt,tr[rt].mn=1ll<<60;tr[rt].mn=min(tr[rt].mn,v);if(l==r)return ;
	int m=(l+r)>>1;if(x<=m)insert(x,v,lson);else insert(x,v,rson);
}
void Update(int x,int L,int R,int v,int l,int r,int &rt)
{
	if(L>R||!x)return;rt=++cnt;tr[rt]=tr[x];if(L<=l&&r<=R){tr[rt].tag+=v;tr[rt].mn+=v;return ;}int m=(l+r)>>1;
	if(L<=m)Update(tr[x].ls,L,R,v,lson);if(m<R)Update(tr[x].rs,L,R,v,rson);tr[rt].mn=min(tr[tr[rt].ls].mn,tr[tr[rt].rs].mn)+tr[rt].tag;
}
ll query(int L,int R,int l,int r,int rt)
{
	if(!rt)return 1ll<<60;if(L<=l&&r<=R)return tr[rt].mn;int m=(l+r)>>1;ll ret=1ll<<60;
	if(L<=m)ret=query(L,R,lson);if(m<R)ret=min(ret,query(L,R,rson));
	return ret+tr[rt].tag;
}
struct node{int to,next,val;}e[N];
int n,Q,head[N],fa[N],in[N],out[N];ll dis[N];
void add(int x,int y,int z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;}
void dfs(int x)
{
	out[x]=in[x]=x;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;dis[to1]=dis[x]+e[i].val;fa[to1]=x;
		dfs(to1);out[x]=max(out[x],out[to1]);
	}
}
void dfs2(int x,int from,int len)
{
	if(x!=1)
		rot[x]=rot[from],
		Update(rot[x],1,n,len,1,n,rot[x]),
		Update(rot[x],in[x],out[x],-len*2,1,n,rot[x]);
	for(int i=head[x];i!=-1;i=e[i].next)dfs2(e[i].to,x,e[i].val);
}
int main()
{
	scanf("%d%d",&n,&Q);memset(head,-1,sizeof(head));tr[0].mn=1ll<<60;
	for(int i=2,x,y;i<=n;i++)scanf("%d%d",&x,&y),add(x,i,y);cnt=0;dfs(1);
	for(int x=1;x<=n;x++)if(head[x]==-1)insert(x,dis[x],1,n,rot[1]);dfs2(1,0,0);
	while(Q--)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		printf("%lld\n",query(l,r,1,n,rot[x]));
	}
}
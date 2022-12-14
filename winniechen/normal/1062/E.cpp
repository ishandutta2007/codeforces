#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
struct node{int to,next;}e[N];
int n,head[N],cnt,m;
int fa[N],top[N],son[N],siz[N],dep[N],dfn[N];
int mn[20][N],mx[20][N],lg[N];
inline int cmp(int x,int y) {
	if(!x||!y) return x+y;
	return dfn[x]<dfn[y]?x:y;
}
inline int cmp1(int x,int y) {
	if(!x||!y) return x+y;
	return dfn[x]>dfn[y]?x:y;
}
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x) {
	siz[x]=1;dfn[x]=++dfn[0];
	for(int i=head[x];i!=-1;i=e[i].next) {
		int to1=e[i].to;
		dep[to1]=dep[x]+1;
		dfs1(to1); 
		siz[x]+=siz[to1];
		if(siz[to1]>siz[son[x]]) son[x]=to1;
	}
}
void dfs2(int x,int t) {
	top[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=son[x]) dfs2(to1,to1);
	}
	
}
int lca(int x,int y) {
	if(!x||!y) return x+y;
	for(;top[x]!=top[y];y=fa[top[y]]) if(dep[top[x]]>dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int get_min(int l,int r) {
	if(l>r) return 0;
	int len=lg[r-l+1];
	return cmp(mn[len][l],mn[len][r-(1<<len)+1]);
}
int get_max(int l,int r) {
	if(l>r) return 0;
	int len=lg[r-l+1];
	return cmp1(mx[len][l],mx[len][r-(1<<len)+1]);
}
int main() {
	scanf("%d%d",&n,&m);memset(head,-1,sizeof(head));
	int i,j;
	for(i=2;i<=n;i++)scanf("%d",&fa[i]),add(fa[i],i);
	dfs1(1); dfs2(1,1);
	lg[0]=-1;
	for(i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(i=1;i<=n;i++) mn[0][i]=mx[0][i]=i;
	for(i=1;(1<<i)<=n;i++) {
		for(j=1;j<=n-(1<<i)+1;j++) {
			mn[i][j]=cmp(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			mx[i][j]=cmp1(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		}
	}
	while(m--) {
		int l,r;
		scanf("%d%d",&l,&r);
		int x=get_min(l,r),y=get_max(l,r),ans1=0,ans2=0;
		int lx=get_min(l,x-1),rx=get_min(x+1,r);
		ans1=lca(cmp(lx,rx),y);
		int ly=get_max(l,y-1),ry=get_max(y+1,r);
		ans2=lca(cmp1(ly,ry),x);
		if(dep[ans1]>dep[ans2])printf("%d %d\n",x,dep[ans1]);
		else printf("%d %d\n",y,dep[ans2]);
	}

	return 0;
}
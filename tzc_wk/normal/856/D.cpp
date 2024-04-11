/*
Contest: -
Problem: Codeforces 856D
Author: tzc_wk
Time: 2020.8.20
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
int head[200005],to[400005],nxt[400005],ecnt=0;
inline void adde(int u,int v){
	to[++ecnt]=v;nxt[ecnt]=head[u];head[u]=ecnt;
}
int fa[200005],top[200005],dep[200005],siz[200005],wson[200005],dfn[200005],nd[200005],tim=0;
inline void dfs1(int x){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];dep[y]=dep[x]+1;dfs1(y);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
inline void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;nd[tim]=x;
	if(wson[x]) dfs2(wson[x],tp);
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];if(y!=wson[x]) dfs2(y,y);
	}
}
inline int getlca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
struct path{
	int u,v,w;
	path(){/*nothing*/}
	path(int _u,int _v,int _w){u=_u;v=_v;w=_w;}
}; vector<path> t[200005];
struct node{
	int l,r,val;
} s[200005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
inline void modify(int k,int ind,int val){
	if(s[k].l==s[k].r){s[k].val+=val;return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid) modify(k<<1,ind,val);
	else modify(k<<1|1,ind,val);
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
inline int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
inline int calc(int u,int v){
	int sum=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		sum+=query(1,dfn[top[u]],dfn[u]);u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	sum+=query(1,dfn[v],dfn[u]);return sum;
}
int dp[200005];
inline void dfs3(int x){
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		dfs3(to[i]);sum+=dp[to[i]];
	}
	dp[x]=sum;
	foreach(it,t[x]) dp[x]=max(dp[x],calc(it->u,it->v)+it->w+sum);
	modify(1,dfn[x],sum-dp[x]);
}
int main(){
	for(int i=2;i<=n;i++){fa[i]=read();adde(fa[i],i);}
	dfs1(1);dfs2(1,1);build(1,1,n);
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		t[getlca(u,v)].pb(path(u,v,w));
	}
	dfs3(1);printf("%d\n",dp[1]);
	return 0;
}
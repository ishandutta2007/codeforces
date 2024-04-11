/*
Contest: -
Problem: Codeforces 916E
Author: tzc_wk
Time: 2020.8.22
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
#define int long long
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
int n=read(),m=read(),a[200005];
vector<int> g[200005];
int bg[200005],ed[200005],fa[200005][20],dep[200005],tim=0,seq[200005];
inline void dfs(int x,int f){
	fa[x][0]=f;bg[x]=++tim;seq[tim]=x;
	foreach(it,g[x]){
		int y=*it;if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
	ed[x]=tim;
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
struct node{
	int l,r,val,lz;
} s[200005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r){
		s[k].val=a[seq[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
inline void pushdown(int k){
	if(s[k].lz){
		s[k<<1].val+=(s[k<<1].r-s[k<<1].l+1)*s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=(s[k<<1|1].r-s[k<<1|1].l+1)*s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
inline void modify(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){
		s[k].val+=(s[k].r-s[k].l+1)*x;s[k].lz+=x;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
inline int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val;
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
inline int jump(int x,int d){
	for(int i=0;i<=18;i++) if(d>>i&1) x=fa[x][i];
	return x;
}
int rt;
inline int _query(int x){
	if(x==rt) return query(1,1,n);
	else if(bg[rt]<bg[x]||bg[rt]>ed[x]) return query(1,bg[x],ed[x]);
	else{
		int son=jump(rt,dep[rt]-dep[x]-1);
		return query(1,1,n)-query(1,bg[son],ed[son]);
    }
}
inline void _modify(int x,int v){
	if(x==rt) modify(1,1,n,v);
	else if(bg[rt]<bg[x]||bg[rt]>ed[x]) modify(1,bg[x],ed[x],v);
	else{
		int son=jump(rt,dep[rt]-dep[x]-1);
		modify(1,1,n,v);modify(1,bg[son],ed[son],-v);
    }
}
int _lca(int u,int v,int p) {
    int x=lca(u,v),y=lca(u,p),z=lca(v,p);
    if(dep[y]>dep[x]) x=y;
    if(dep[z]>dep[x]) x=z;
    return x;
}
signed main(){
	fz(i,1,n) a[i]=read();
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].pb(v);g[v].pb(u);
	}
	dep[1]=1;dfs(1,0);build(1,1,n);
	fz(i,1,18) fz(j,1,n) fa[j][i]=fa[fa[j][i-1]][i-1];
	rt=1;
	while(m--){
		int opt=read();
		if(opt==1) rt=read();
		else if(opt==2){
			int u=read(),v=read(),x=read();
			_modify(_lca(u,v,rt),x);
		}
		else{
			int x=read();
			cout<<_query(x)<<endl;
		}
	}
	return 0;
}
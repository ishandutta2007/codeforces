#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
typedef unsigned long long ull;
ull val[SZ];
int n,q,a[SZ];
Edg
int sz[SZ],son[SZ],fa[SZ],dep[SZ];
int p1[SZ],G=0,od[SZ];
void dfs(int x,int f=0)
{
	sz[x]=1; fa[x]=f; dep[x]=dep[f]+1;
	p1[x]=++G; od[G]=x;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
	od[++G]=x;
}
int top[SZ],dd[SZ],C=0,ls[SZ];
void dfs2(int x,int t,int f=0)
{
	dd[x]=++C; top[x]=t;
	if(son[x]) dfs2(son[x],t,x);
	for esb(x,e,b)
		if(b!=f&&b!=son[x])
			dfs2(b,b,x);
	ls[x]=C;
}
int lca(int a,int b)
{
	while(top[a]!=top[b])
		if(dep[top[a]]>dep[top[b]]) a=fa[top[a]];
		else b=fa[top[b]];
	if(dep[a]>dep[b]) return b; return a;
}
int dis(int a,int b)
{
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
int rt[SZ];
#define SS 22345678
int ch[SS][2],an;
ull vv[SS];
inline ull qry_qz(int x,int l,int r,int ql,int qr) {
	if(r<ql||qr<l||x==0) return 0;
	if(ql<=l&&r<=qr) return vv[x];
	int m=(l+r)>>1;
	return qry_qz(ch[x][0],l,m,ql,qr)^qry_qz(ch[x][1],m+1,r,ql,qr);
}
inline int ins(int x,int l,int r,int s,ull w) {
	int y=++an; vv[y]=vv[x]^w;
	if(l==r) return y;
	int m=(l+r)>>1;
	if(s<=m)
		ch[y][1]=ch[x][1],
		ch[y][0]=ins(ch[x][0],l,m,s,w);
	else
		ch[y][0]=ch[x][0],
		ch[y][1]=ins(ch[x][1],m+1,r,s,w);
	return y;
}
int walk(int r1,int r2,int l,int r,int ql,int qr,int v) {
	ql=max(ql,l); qr=min(qr,r);
	if(ql>qr) return -1;
	ll ex=(ql<=v&&v<=qr)?val[v]:0;
	if(l==ql&&r==qr&&(vv[r1]^vv[r2]^ex)==0) return -1;
	if(l==r) return l;
	int m=(l+r)>>1;
	int s=walk(ch[r1][0],ch[r2][0],l,m,ql,qr,v);
	if(s!=-1) return s;
	return walk(ch[r1][1],ch[r2][1],m+1,r,ql,qr,v);
}
int main() 
{
//	cerr<<sizeof(ch)/1024./1024.<<"M\n";
	srand(chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i) {
		val[i]=0;
		for(int j=0;j<10;++j)
			val[i]=val[i]*(RAND_MAX+1)+rand();
//		val[i]=1LL<<i;
	}
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1); dfs2(1,1);
	for(int i=1,x;i<=G;++i)
		x=od[i],
		rt[i]=ins(rt[i-1],1,n,a[x],val[a[x]]);
	while(q--) {
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		int p=lca(u,v);
		auto qry=[&](int l,int r) {
			ull ans=qry_qz(rt[p1[u]],1,n,l,r)^qry_qz(rt[p1[v]],1,n,l,r);
			if(l<=a[p]&&a[p]<=r) ans^=val[a[p]];
			return ans;
		};
		printf("%d\n",walk(rt[p1[u]],rt[p1[v]],1,n,l,r,a[p]));
	}
}
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=150010;
const ll INF=1LL<<50;
int n;
vector<int> g[maxn];
bool vis[maxn];
int root,mxsz[maxn],sz[maxn],N;
ll val[maxn],ans;
void Dfs1(int u,int p) {
	sz[u]=1;
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (v==p||vis[v]) continue;
		Dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void Dfs2(int u,int p) {
	mxsz[u]=0;
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (v==p||vis[v]) continue;
		Dfs2(v,u);
		mxsz[u]=max(mxsz[u],sz[v]);
	}
	mxsz[u]=max(mxsz[u],N-sz[u]);
	if (!root||mxsz[root]>mxsz[u]) root=u;
}
struct line {
	ll k,b;
} tr[maxn*40];
ll F(line A,ll x) { return A.k*x+A.b; }
int RT,tot,ls[maxn*40],rs[maxn*40];
void add(int l,int r,int &root,line A) {
	if (!root) root=++tot,tr[root]=(line){0,-INF},ls[root]=rs[root]=0;
	int mid=(l+r)/2;
	bool t1=F(A,l)>F(tr[root],l);
	if (l==r) {
		if (t1) tr[root]=A;
		return;
	}
	bool t2=F(A,mid+1)>F(tr[root],mid+1);
	if (t2) swap(tr[root],A);
	if (t1!=t2) add(l,mid,ls[root],A);
	else add(mid+1,r,rs[root],A);
}
ll query(int l,int r,int root,ll x) {
	if (!root) return -INF;
	int mid=(l+r)/2;
	ll res=F(tr[root],x);
	if (x<=mid) res=max(res,query(l,mid,ls[root],x));
	else res=max(res,query(mid+1,r,rs[root],x));
	return res;
}
void dfs1(int u,int p,int dep,ll s1,ll s2) {
	s2+=val[u]; s1+=s2;
	ans=max(ans,query(0,n,RT,dep)+s1);
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (v==p||vis[v]) continue;
		dfs1(v,u,dep+1,s1,s2);
	}
}
void dfs2(int u,int p,int dep,ll s1,ll s2) {
	s1+=val[u]*dep;
	s2+=val[u];
	add(0,n,RT,(line){s2,s1});
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (v==p||vis[v]) continue;
		dfs2(v,u,dep+1,s1,s2);
	}
}
void init() {
	for (int i=1;i<=tot;i++) ls[i]=rs[i]=0;
	tot=RT=0;
}
void solve(int u) {
	vis[u]=1;
	init();
	add(0,n,RT,(line){val[u],val[u]});
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (vis[v]) continue;		
		dfs1(v,u,1,0,0);
		dfs2(v,u,2,val[u],val[u]);
	}
	init();
	for (int i=g[u].size()-1,v;i>=0;i--) {
		v=g[u][i];
		if (vis[v]) continue;
		dfs1(v,u,1,0,0);
		dfs2(v,u,2,val[u],val[u]);
	}
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (vis[v]) continue;
		Dfs1(v,u);
		N=sz[v];
		root=0;
		Dfs2(v,u);
		solve(root);
	}
	
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) read(val[i]);
	Dfs1(1,0);
	N=n;
	Dfs2(1,0);
	solve(root);
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
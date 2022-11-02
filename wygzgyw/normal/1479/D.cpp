#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef unsigned long long ull;
const int INF=1e6;
const int maxn=(3e5)+10;
const int maxm=(1e7)+10;
int n,m,a[maxn],fa[maxn][20],dep[maxn],tot,head[maxn],nxt[maxn*2],to[maxn*2];
int rt[maxn],ls[maxm],rs[maxm];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
ull haxi[maxn],tr[maxm];
ull get() {
	ull res=0;
	for (int i=0;i<=62;i++)
		if (rand()&1) res|=((ull)1<<i);
	return res;
}
void add(int x,int l,int r,int &root,ull delta) {
	tot++; ls[tot]=ls[root],rs[tot]=rs[root],tr[tot]=(tr[root]^delta);
	root=tot;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,ls[root],delta);
	else add(x,mid+1,r,rs[root],delta);
}
void dfs(int u,int p) {
	dep[u]=dep[p]+1,fa[u][0]=p;
	rt[u]=rt[p];
	add(a[u],1,n,rt[u],haxi[a[u]]);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
	}
}
int query(int L,int R,int l,int r,int x,int y,int delta) {
	if (l>R||r<L) return -1;
	int mid=(l+r)>>1;
	if (L<=l&&r<=R) {
		ull h=0; if (l<=delta&&delta<=r) h=haxi[delta];
		if ((tr[x]^tr[y]^h)==0) return -1;
		if (l==r) return l;
		ull lh=0; if (l<=delta&&delta<=mid) lh=haxi[delta];
		if (tr[ls[x]]^tr[ls[y]]^lh) return query(L,R,l,mid,ls[x],ls[y],delta);
		return query(L,R,mid+1,r,rs[x],rs[y],delta);
	}
	int t1=query(L,R,l,mid,ls[x],ls[y],delta);
	if (t1!=-1) return t1;
	int t2=query(L,R,mid+1,r,rs[x],rs[y],delta);
	return t2;
}
int main() {
	//freopen("1.txt","r",stdin);
	srand(time(0));
	read(n); read(m); int x,y,z;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++) {
		read(x),read(y);
		add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++) {
		haxi[i]=get();
	}
	tot=0;
	dfs(1,0);
	for (int i=1;i<=19;i++) for (int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int l,r;
	while (m--) {
		read(x),read(y); read(l); read(r);
		z=lca(x,y);
		printf("%d\n",query(l,r,1,n,rt[x],rt[y],a[z]));
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
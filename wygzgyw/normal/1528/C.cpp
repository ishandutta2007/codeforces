#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
const int maxn=(3e5)+10;
int T,n;
vector<int> g[maxn];
int tot,bg[maxn],ed[maxn];
namespace Seg {
	int tr[maxn*4],lazy[maxn*4];
	void pushdown(int root) {
		if (lazy[root]!=-1) tr[root*2]=tr[root*2+1]=lazy[root*2]=lazy[root*2+1]=lazy[root],lazy[root]=-1;
	}
	void clear() { for (int i=1;i<=n*4;i++) tr[i]=0,lazy[i]=-1; }
	void add(int L,int R,int l,int r,int root,int delta) {
		if (L<=l&&r<=R) { tr[root]=lazy[root]=delta; return; }
		int mid=(l+r)>>1; pushdown(root);
		if (L<=mid) add(L,R,l,mid,root<<1,delta);
		if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	}
	int query(int x,int l,int r,int root) {
		if (l==r) return tr[root];
		int mid=(l+r)>>1; pushdown(root);
		if (x<=mid) return query(x,l,mid,root<<1);
		return query(x,mid+1,r,root<<1|1);
	}
};
vector<int> h[maxn];
int bk[maxn];
void dfs(int u) {
	bg[u]=++tot; bk[tot]=u;
	for (int v : h[u]) dfs(v);
	ed[u]=tot;
}
int ans;
void dfs2(int u) {
	int x=Seg::query(bg[u],1,n,1);
	if (x) {
		Seg::add(bg[x],ed[x],1,n,1,0);
		Seg::add(bg[u],ed[u],1,n,1,u);
	} else tot++,Seg::add(bg[u],ed[u],1,n,1,u);
	ans=max(ans,tot);
	for (int v : g[u]) dfs2(v);
	if (x) {
		Seg::add(bg[x],ed[x],1,n,1,x);
	} else tot--,Seg::add(bg[u],ed[u],1,n,1,0);
	assert(Seg::query(bg[u],1,n,1)==x);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) { int x;
		read(n); for (int i=1;i<=n;i++) g[i].clear(),h[i].clear();
		for (int i=2;i<=n;i++) read(x),g[x].push_back(i);
		for (int i=2;i<=n;i++) read(x),h[x].push_back(i);
		tot=0;
		dfs(1); tot=ans=0;
		Seg::clear();
		dfs2(1);
		printf("%d\n",ans);
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
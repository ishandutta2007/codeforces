// wygzgyw
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
#define MP make_pair
typedef long long ll;
const int maxn=(8e6)+10;
int n,m; ll N;
int ls[maxn],rs[maxn]; bool ans[maxn];
int tag[maxn],tot;
vector<int> g[maxn/10],to[maxn];
struct node {
	ll a,b; int op;
} d[maxn];
bool leaf(int x) { return !ls[x]&&!rs[x]; }
void link(int x,int y) {
	if (leaf(x)&&leaf(y)) {
		if (tag[x]<tag[y]) to[x].push_back(y);
		else to[y].push_back(x);
		return;
	}
	if (leaf(x)) link(x,ls[y]),link(x,rs[y]);
	else if (leaf(y)) link(y,ls[x]),link(y,rs[x]);
	else link(ls[x],ls[y]),link(rs[x],rs[y]);
}
void pushdown(int root) {
	if (!ls[root]) ls[root]=++tot;
	if (!rs[root]) rs[root]=++tot;
	if (tag[root]) tag[ls[root]]=tag[rs[root]]=tag[root],tag[root]=0;
}
void modify(ll L,ll R,ll l,ll r,int root,int delta) {
	if (L<=l&&r<=R) { tag[root]=delta; return; }
	ll mid=(l+r)>>1; pushdown(root);
	if (L<=mid) modify(L,R,l,mid,ls[root],delta);
	if (mid<R) modify(L,R,mid+1,r,rs[root],delta);
}
void dfs(ll l,ll r,int root) {
	if (leaf(root)) { g[tag[root]].push_back(root); return; }
	ll mid=(l+r)>>1; pushdown(root);
	dfs(l,mid,ls[root]),dfs(mid+1,r,rs[root]);
}
int query(ll x,ll l,ll r,int root) {
	if (leaf(root)) return root;
	ll mid=(l+r)>>1; if (x<=mid) return query(x,l,mid,ls[root]); return query(x,mid+1,r,rs[root]);
}
int fa[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
void merge(int x,int y) { fa[find(x)]=find(y); }
int main() {
	read(n),read(m); N=(1LL<<n)-1;
	char s[10]; int cnt=0;
	for (int i=1;i<=m;i++) {
		scanf("%s",s+1);
		read(d[i].a),read(d[i].b);
		if (s[1]=='a') d[i].op=++cnt;
	}
	tag[tot=1]=m+1;
	for (int i=1;i<=m;i++) if (!d[i].op) modify(d[i].a,d[i].b,0,N,1,i);
	dfs(0,N,1);
	for (int i=1;i<=tot;i++) if (!leaf(i)) link(ls[i],rs[i]);
	for (int i=1;i<=tot;i++) fa[i]=i;
	for (int u : g[m+1]) for (int v : to[u]) merge(u,v);
	for (int i=m;i>=1;i--) {
		if (d[i].op) {
			int x=query(d[i].a,0,N,1),y=query(d[i].b,0,N,1);
			ans[d[i].op]=find(x)==find(y);
		} else {
			for (int u : g[i]) for (int v : to[u]) merge(u,v);
		}
	}
	for (int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
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
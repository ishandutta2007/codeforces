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
const int maxn=(6e5)+10;
int n,q,N,val[maxn];
int st[maxn*2][21],lg[maxn*2],dep[maxn];
struct node { int x,y,z; } E[maxn];
bool cmp(node A,node B) { return A.z<B.z; }
vector<int> g[maxn]; int rt,fa[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int dfn[maxn],bk[maxn],tot,idx;
void dfs(int u) {
	st[++tot][0]=u,bk[u]=tot; dfn[u]=++idx;
	for (int &v : g[u]) dep[v]=dep[u]+1,dfs(v),st[++tot][0]=u;
}
int tr[maxn*4],lazy[maxn*4],rem[maxn*4];
int MN(int x,int y) { if (dep[x]<dep[y]) return x; return y; }
int lca(int x,int y) {
	if (!x||!y) return x+y;
	x=bk[x],y=bk[y]; if (x>y) swap(x,y);
	int j=lg[y-x+1]; return MN(st[x][j],st[y-(1<<j)+1][j]);
}
void build(int l,int r,int root) {
	lazy[root]=-1;
	if (l==r) { rem[root]=l; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	rem[root]=lca(rem[root<<1],rem[root<<1|1]);
}
void puttag(int root,int delta) {
	if (!delta) tr[root]=0;
	else tr[root]=rem[root];
	lazy[root]=delta;
}
void pushdown(int root) {
	if (lazy[root]!=-1) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=-1;
}
void modify(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1;
	pushdown(root);
	if (L<=mid) modify(L,R,l,mid,root<<1,delta);
	if (mid<R) modify(L,R,mid+1,r,root<<1|1,delta);
	tr[root]=lca(tr[root<<1],tr[root<<1|1]);
}
bool query(int x,int l,int r,int root) {
	if (l==r) return tr[root]>0;
	int mid=(l+r)>>1; pushdown(root);
	if (x<=mid) return query(x,l,mid,root<<1);
	return query(x,mid+1,r,root<<1|1);
}
int main() {
	read(n),read(q);
	for (int i=1;i<n;i++) read(E[i].x),read(E[i].y),read(E[i].z);
	sort(E+1,E+n,cmp);
	val[0]=-1;
	for (int i=1;i<=n*2;i++) fa[i]=i,val[i]=-1;
	for (int i=1;i<n;i++) {
		int x=find(E[i].x),y=find(E[i].y);
		int now=i+n; val[now]=E[i].z;
		g[now].push_back(x),g[now].push_back(y),fa[x]=fa[y]=now;
	}
	N=rt=n*2-1;
	dfs(rt);
	for (int i=2;i<=tot;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=20;i++) for (int j=1;j+(1<<i)-1<=tot;j++)
		st[j][i]=MN(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	build(1,N,1);
	while (q--) {
		int op,l,r,x;
		read(op);
		if (op==1) read(l),read(r),modify(l,r,1,N,1,1);
		else if (op==2) read(l),read(r),modify(l,r,1,N,1,0);
		else {
			read(x);
			int tmp=query(x,1,N,1);
			if (!tmp) modify(x,x,1,N,1,1);
			printf("%d\n",val[tr[1]]);
			if (!tmp) modify(x,x,1,N,1,0);
		}
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
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
const int maxn=(1e5)+10;
int n,m;
bitset<1010> tr[maxn*4];
bitset<1010> B,res;
void rotate(bitset<1010> &A,int r) {
	if (!r) return;
	A=(A>>(m-r))|(A<<r);
}
vector<int> g[maxn];
int bg[maxn],ed[maxn];
int tot,a[maxn],b[maxn];
void dfs(int u,int p) {
	bg[u]=++tot; b[tot]=a[u];
	for (int &v : g[u]) if (v!=p) dfs(v,u);
	ed[u]=tot;
}
void build(int l,int r,int root) {
	if (l==r) { tr[root].set(b[l]); return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=tr[root<<1]|tr[root<<1|1];
}
int lazy[maxn*4];
void puttag(int root,int delta) { rotate(tr[root],delta); lazy[root]=(lazy[root]+delta)%m; }
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void modify(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) modify(L,R,l,mid,root<<1,delta);
	if (mid<R) modify(L,R,mid+1,r,root<<1|1,delta);
	tr[root]=tr[root<<1]|tr[root<<1|1];
}
void query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) { res|=tr[root]; return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]),a[i]%=m;
	int x,y,q;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	vector<int> V;
	for (int i=2;i<m;i++) {
		bool flag=1;
		for (int j=2;j<i&&flag;j++) if (i%j==0) flag=0;
		if (flag) V.push_back(i);
	}
	build(1,n,1);
	read(q);
	while (q--) {
		int op; read(op),read(x);
		if (op==1) read(y),y%=m,modify(bg[x],ed[x],1,n,1,y);
		else {
			res.reset();
			query(bg[x],ed[x],1,n,1);
			int ans=0;
			for (int &x : V) if (res.test(x)) ans++;
			printf("%d\n",ans);
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
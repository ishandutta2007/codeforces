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
const ll INF=1e18;
const int maxn=(2e5)+10;
int T,n;
int a[maxn];
ll s[maxn];
ll lazy[maxn*4],tr[maxn*4];
void puttag(int root,ll delta) {
	tr[root]+=delta,lazy[root]+=delta;
}
void pushdown(int root) {
	puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void pushup(int root) {
	tr[root]=min(tr[root<<1],tr[root<<1|1]);
}
void build(int l,int r,int root) {
	lazy[root]=0;
	if (l==r) { tr[root]=-s[l]; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void add(int L,int R,int l,int r,int root,ll delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
ll query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1; pushdown(root); ll res=INF;
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res=min(res,query(L,R,mid+1,r,root<<1|1));
	return res;
}
int st[maxn],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
		build(1,n,1);
		tot=0; st[0]=n+1;
		int flag=1;
		for (int i=n;i>=1;i--) {
			while (tot&&a[st[tot]]<a[i]) add(st[tot],st[tot-1]-1,1,n,1,a[i]-a[st[tot]]),tot--;
			add(i,i,1,n,1,a[i]);
			st[++tot]=i;
			if (query(i,n,1,n,1)+s[i-1]<0) { flag=0; break; }
		}
		if (flag) puts("YES"); else puts("NO");
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
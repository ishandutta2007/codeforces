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
const int maxn=(2e5)+10;
int T,n,k;
ll tr[maxn*4],a[maxn];
int lazy[maxn*4],pos[maxn*4];
void pushup(int root) {
	if (tr[root<<1]<tr[root<<1|1]) tr[root]=tr[root<<1],pos[root]=pos[root<<1];
	else tr[root]=tr[root<<1|1],pos[root]=pos[root<<1|1];
}
void puttag(int root,int delta) {
	tr[root]+=delta,lazy[root]+=delta;
}
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void build(int l,int r,int root) {
	lazy[root]=0;
	if (l==r) { tr[root]=-a[l]+(n-l); pos[root]=l; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void clear(int x,int l,int r,int root) {
	if (l==r) { tr[root]=1e9; return; }
	int mid=(l+r)>>1;
	if (x<=mid) clear(x,l,mid,root<<1);
	else clear(x,mid+1,r,root<<1|1);
	pushup(root);
}
int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		ll sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		build(1,n,1);
		for (int i=1;i<=k;i++) {
			int x=pos[1];
			if (tr[1]>=0) break;
			sum+=tr[1];
			if (x>1) add(1,x-1,1,n,1,-1);
			if (x<n) add(x+1,n,1,n,1,-1);
			clear(x,1,n,1);
		}
		printf("%lld\n",sum);
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
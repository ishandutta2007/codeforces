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
int n,m,q;
ll a[maxn],b[maxn];
namespace T1 {
	ll tr[maxn*4],lazy[maxn*4]; int sz[maxn*4];
	void build(int l,int r,int root) {
		sz[root]=r-l+1;
		if (l==r) { tr[root]=b[l]; return; }
		int mid=(l+r)>>1;
		build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		tr[root]=tr[root<<1]+tr[root<<1|1];
	}
	void puttag(int root,ll delta) {
		tr[root]+=delta*sz[root]; lazy[root]+=delta;
	}
	void pushdown(int root) {
		if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
	}
	void add(int L,int R,int l,int r,int root,ll delta) {
		if (L<=l&&r<=R) { puttag(root,delta); return; }
		int mid=(l+r)>>1; pushdown(root);
		if (L<=mid) add(L,R,l,mid,root<<1,delta);
		if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
		tr[root]=tr[root<<1]+tr[root<<1|1];
	}
	ll query(int L,int R,int l,int r,int root) {
		if (L>R) return 0;
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1; pushdown(root); ll res=0;
		if (L<=mid) res=query(L,R,l,mid,root<<1); if (mid<R) res+=query(L,R,mid+1,r,root<<1|1);
		return res;
	}
};
namespace T2 {
	ll tr[maxn*4];
	void build(int l,int r,int root) {
		if (l==r) { tr[root]=b[l]-(l>2?b[l-1]:0); return; }
		int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1);
		tr[root]=tr[root<<1]+tr[root<<1|1];
	}
	void add(int x,int l,int r,int root,int delta) {
		tr[root]+=delta; if (l==r) return;
		int mid=(l+r)>>1; if (x<=mid) add(x,l,mid,root<<1,delta); else add(x,mid+1,r,root<<1|1,delta);
	}
	int query(int l,int r,int root,ll delta) {
		if (l==r) {
			if (delta<tr[root]) return l-1; return l;
		}
		int mid=(l+r)>>1;
		if (tr[root<<1]>=delta) return query(l,mid,root<<1,delta);
		return query(mid+1,r,root<<1|1,delta-tr[root<<1]);
	}
};
int main() {
	read(n),read(m),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	for (int i=1;i<=m;i++) read(b[i]);
	for (int i=m;i>=1;i--) b[i]=b[i]-b[i-1];
	ll sum=0,ans;
	for (int i=2;i<=m;i++) sum+=b[i]*(m-i+1);
	T1::build(2,m,1),T2::build(2,m,1);
	while (q--) {
		int op,k,d;
		read(op),read(k),read(d);
		if (op==1) {
			for (int i=n-k+1;i<=n;i++) a[i]+=d;
		} else {
			if (k==m) b[1]+=d,k--;
			sum+=(ll)k*(k+1)/2*d;
			T1::add(m-k+1,m,2,m,1,d);
			T2::add(m-k+1,2,m,1,d);
		}
		ans=sum+(a[1]+b[1])*(n+m-1);
		for (int i=2;i<=n;i++) {
			int pos=T2::query(2,m,1,a[i]);
			ans+=T1::query(2,pos,2,m,1)+(n+m+1-(pos+i))*a[i];
		}
		printf("%lld\n",ans);
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
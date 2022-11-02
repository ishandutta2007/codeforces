#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=0x7f7f7f7f;
const int maxn=(2e5)+10;
int n,m,A[maxn],B[maxn],ans;
ll sum;
int N,lsh[maxn*2];
struct node { int l,r,x; } a[maxn],b[maxn];
bool cmpl(node x,node y) { return x.l<y.l; }
bool cmpr(node x,node y) { return x.r<y.r; }
namespace Seg {
	int tr[maxn*8];
	void init() {
		for (int i=1;i<=N*4;i++) tr[i]=INF;
	}
	void add(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]=min(tr[root],delta); return; }
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	int query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=min(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
};
int F(int x) {
	return lower_bound(lsh+1,lsh+N+1,x)-lsh;
}
void solve() {
	int pos=0,mx=0;
	for (int i=1;i<=n;i++) {
		while (pos<m&&b[pos+1].l<=a[i].l) {
			pos++; mx=max(mx,b[pos].r);
		}
		if (mx>=a[i].r) ans=max(ans,a[i].r-a[i].l);
	}
	pos=m+1; Seg::init();
	for (int i=n;i>=1;i--) {
		while (pos>1&&b[pos-1].l>=a[i].l) {
			pos--;
			Seg::add(b[pos].x,1,N,1,b[pos].l);
		}
		ans=max(ans,a[i].r-Seg::query(a[i].x,N,1,N,1));
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	int tN; read(tN);
	for (int i=1;i<=tN;i++) read(A[i]);
	for (int i=1;i<=tN;i++) {
		read(B[i]);
		sum+=abs(A[i]-B[i]);
		if (A[i]<B[i]) a[++n]=(node){A[i],B[i]};
		else if (A[i]>B[i]) b[++m]=(node){B[i],A[i]};
		lsh[++N]=max(A[i],B[i]);
	}
	sort(lsh+1,lsh+N+1); N=unique(lsh+1,lsh+N+1)-lsh-1;
	for (int i=1;i<=n;i++) a[i].x=F(a[i].r);
	for (int i=1;i<=m;i++) b[i].x=F(b[i].r);
	if (!n||!m) { printf("%lld\n",sum); return 0; }
	sort(a+1,a+n+1,cmpl);
	sort(b+1,b+m+1,cmpl);
	solve();
	swap(n,m);
	for (int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
	solve();
	//printf("%lld\n",sum);
	printf("%lld\n",sum-(ll)ans*2);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/
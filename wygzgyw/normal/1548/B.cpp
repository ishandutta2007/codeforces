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
int T,n,ans;
ll a[maxn],b[maxn],tr[maxn*4];
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y; return gcd(y,x%y);
}
void build(int l,int r,int root) {
	if (l==r) {
		tr[root]=b[l]; return;
	}
	int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=gcd(tr[root<<1],tr[root<<1|1]);
}
ll now; int mx;
void query(int L,int R,int l,int r,int root) {
	if (now==1) return;
	int mid=(l+r)>>1;
	if (L<=l&&r<=R) {
		ll tmp=gcd(now,tr[root]);
		if (tmp>1) { mx=r; now=tmp; return; }
		if (l==r) { now=tmp; return; }
		tmp=gcd(now,tr[root<<1]);
		if (tmp==1) query(L,R,l,mid,root<<1);
		else now=tmp,mx=mid,query(L,R,mid+1,r,root<<1|1);
		return;
	}
	if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n==1) { puts("1"); continue; }
		for (int i=1;i<n;i++) b[i]=abs(a[i+1]-a[i]);
		n--;
		ans=1;
		build(1,n,1);
		for (int i=1;i<=n;i++) {
			if (b[i]==1) continue;
			now=0; mx=i;
			query(i,n,1,n,1);
			ans=max(ans,mx-i+2);
		}
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
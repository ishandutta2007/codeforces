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
const int maxn=(3e5)+10;
int T,n;
ll a[maxn],mx;
bool check(ll mid) {
	ll c1=mid-mid/2,c2=mid/2;
	for (int i=1;i<=n;i++) {
		ll tmp=mx-a[i];
		ll now=min(c2,tmp/2);
		c2-=now,tmp-=now*2;
		c1-=tmp;
	}
	return c1>=0;
}
ll solve() {
	ll l=0,r=1e18,mid,res=-1;
	while (l<=r) {
		mid=(l+r)>>1;
		if (check(mid)) res=mid,r=mid-1; else l=mid+1;
	} return res;
}
int main() {
	read(T);
	while (T--) {
		mx=0; read(n);
		for (int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
		ll ans=solve();
		mx++; ans=min(ans,solve());
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
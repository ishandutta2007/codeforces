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
int n,q;
ll a[maxn],f[maxn];
ll up(ll x,ll y) { return (x+y-1)/y; }
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
	for (int i=1;i<=n;i++) f[i]=max(f[i-1],up(a[i],i));
	for (int i=1;i<=n;i++) f[i]=max(f[i],up(a[n],i)),f[i]*=-1;
	read(q);
	while (q--) {
		ll x; read(x);
		if (-f[n]>x) { puts("-1"); continue; }
		int ans=lower_bound(f+1,f+n+1,-x)-f;
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
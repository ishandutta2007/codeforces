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
const ll mod=(1e9)+7;
int T;
ll st,ed,d,a,b,l,r;
ll calc(ll d) {
	ll x=(b/d)%mod; return x*x%mod;
}
ll lcm(ll x,ll y) { return x/__gcd(x,y)*y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T); ll x,y;
	while (T--) {
		read(l),read(a),read(x),r=l+(x-1)*a;
		read(st),read(b),read(y),ed=st+(y-1)*b;
		if (b%a!=0) { puts("0"); continue; }
		if (l<=st&&ed<=r); else { puts("0"); continue; }
		if ((st-l)%a!=0) { puts("0"); continue; }
		if (st-b<l||ed+b>r) { puts("-1"); continue; }
		ll ans=0;
		for (d=1;d*d<=b;d++) if (b%d==0) {
			if (lcm(a,d)==b) ans+=calc(d);
			if (b/d!=d&&lcm(a,b/d)==b) ans+=calc(b/d);
			ans%=mod;
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
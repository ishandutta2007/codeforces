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
const int maxn=10010;
ll n,m,k,a[maxn],b[maxn];
ll cheng(ll x,ll y,ll mod) {
	return ((__int128)x*y)%mod;
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) { x=1,y=0; return a; }
	ll tmp=exgcd(b,a%b,y,x);
	y-=(a/b)*x; return tmp;
}

int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m),read(k);
	ll now=0;
	for (int i=1;i<=k;i++) {
		read(a[i]);
		if (i==1) { now=a[i]; if (now>n) { puts("NO"); return 0; } continue; }
		ll g=__gcd(now,a[i]);
		if (now/g>n/a[i]) { puts("NO"); return 0; }
		now=now/g*a[i];
		b[i]=a[i]-i+1;
		b[i]=(b[i]%a[i]+a[i])%a[i];
		//printf("%lld %lld\n",a[i],b[i]);
	}
	ll ans=b[1],M=a[1],x,y;
	//printf("%lld %lld\n",ans,M);
	for (int i=2;i<=k;i++) {
		ll tmp=(b[i]-ans)%a[i]; tmp=(tmp%a[i]+a[i])%a[i];
		ll g=exgcd(M,a[i],x,y);
		//printf(" %lld %lld %lld\n",a[i],b[i],g);
		if (tmp%g!=0) { puts("NO"); return 0; }
		x=cheng(x,tmp/g,a[i]/g);
		ans+=M*x;
		M=M/g*a[i];
		ans=(ans+M)%M;
	}
	if (ans==0) ans+=M;
//	printf("%lld %lld\n",ans,M);
	if (ans+k-1>m) { puts("NO"); return 0; }
	for (int i=1;i<=k;i++) if (__gcd(now,ans+i-1)!=a[i]) { puts("NO"); return 0; }
	puts("YES");
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
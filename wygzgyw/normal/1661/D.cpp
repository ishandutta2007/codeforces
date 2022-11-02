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
int n;
ll k,a[maxn],ans,b[maxn];
int main() {
	read(n),read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	reverse(a+1,a+n+1);
	ll s1=0,s2=0;
	for (int i=1;i<=n;i++) {
		if (i-k>=1) {
			s1-=b[i-k],s2-=b[i-k]*(i-k);
		}
		a[i]-=(k-i)*s1+s2;
		if (a[i]>0&&i<=n-k) {
			b[i]=(a[i]%k==0?a[i]/k:a[i]/k+1);
			ans+=b[i];
			s1+=b[i],s2+=b[i]*i;
		}
	}
	ll mx=0;
	for (int i=n-k+1,t=k;i<=n;i++,t--) {
		mx=max(mx,a[i]%t==0?a[i]/t:a[i]/t+1);
	}
	ans+=mx;
	printf("%lld\n",ans);
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
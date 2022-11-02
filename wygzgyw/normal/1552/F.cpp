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
const int mod=998244353;
const int maxn=(2e5)+10;
int n,x[maxn],y[maxn],op[maxn],s[maxn],a[maxn],ans;

int main() {
	read(n);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]),read(op[i]);
	for (int i=1;i<=n;i++) {
		int pos=lower_bound(x+1,x+n+1,y[i])-x;
		a[i]=((ll)s[i-1]-s[max(pos,1)-1]+mod+x[i]-y[i])%mod;
		s[i]=(s[i-1]+a[i])%mod;
		if (op[i]) ans=(ans+a[i])%mod;
	}
	ans=(ans+x[n]+1)%mod;
	printf("%d\n",ans);
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
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
const int maxn=(2e6)+10;
int n,a[maxn];
ll ans=1e18;
bool check(ll k) {
	if (k<0) return 0;
	ll m=a[1]+k,t=sqrt(m*1.0);
	while (t*t>m) t--;
	while ((t+1)*(t+1)<=m) t++;
	while (1) {
		int p=upper_bound(a+1,a+n+1,t*t+t-k)-a;
		if (p>n) return 1;
		if (a[p]+k<(t+1)*(t+1)) return 0;
		t++;
	}
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	n=unique(a+1,a+n+1)-a-1;
	if (check(0)) { puts("0"); return 0; }
	for (int i=1;i<=n;i++) {
		for (int j=1;i==1||j<=a[i]-a[i-1]+1;j++) {
			if (check((ll)j*j-a[i])) ans=min(ans,(ll)j*j-a[i]);
			if ((ll)j*j-a[i]>ans) break;
		}
	}
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
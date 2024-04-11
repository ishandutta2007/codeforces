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
const ll INF=1e18;
const int maxn=5010;
int n,a[maxn];
ll b[maxn];
int tot;
ll ans=INF;
ll solve() {
	ll res=0,lst=0;
	for (int i=1;i<=tot;i++) {
		ll nxt=lst/b[i]*b[i]+b[i];
		res+=nxt/b[i];
		lst=nxt;
	}
	return res;
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) {
		tot=0;
		for (int j=i-1;j>=1;j--) b[++tot]=a[j];
		ll tmp=solve();
		tot=0;
		for (int j=i+1;j<=n;j++) b[++tot]=a[j];
		tmp+=solve();
		ans=min(ans,tmp);
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
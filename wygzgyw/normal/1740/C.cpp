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
const ll INF=1e18;
int T,n;
ll a[maxn],suf[maxn];
ll solve() {
	suf[n]=-INF;
	for (int i=n-1;i>=1;i--) {
		suf[i]=max(suf[i+1],a[i+1]*2-a[i]);
	}
	ll ans=-INF;
	for (int i=1;i<n-1;i++) ans=max(ans,suf[i+1]-a[i]);
	return ans;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);
		ll ans=solve();
		for (int i=1;i<=n;i++) a[i]=-a[i];
		reverse(a+1,a+n+1);
		ans=max(ans,solve());
		printf("%lld\n",ans);
	}
	return 0;
}
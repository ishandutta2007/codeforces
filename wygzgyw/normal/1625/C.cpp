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
int n,K; ll L;
ll dp[510][510];
ll d[510],a[510];
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
	read(n),read(L),read(K);
	for (int i=1;i<=n;i++) read(d[i]);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j]=INF;
	dp[1][1]=0;
	for (int i=2;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			for (int k=1;k<i;k++) {
				chkmin(dp[i][j],dp[k][j-1]+(d[i]-d[k])*a[k]);
			}
		}
	}
	ll ans=INF;
	for (int i=1;i<=n;i++) for (int k=0;k<=K;k++) chkmin(ans,dp[i][n-k]+(L-d[i])*a[i]);
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
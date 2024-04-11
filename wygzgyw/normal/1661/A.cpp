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
int T,n;
ll dp[30][2],a[30][2];
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i][0]);
		for (int i=1;i<=n;i++) read(a[i][1]);
		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e18;
		dp[1][0]=0;
		for (int i=2;i<=n;i++) for (int op=0;op<=1;op++) {
			for (int pre=0;pre<=1;pre++) chkmin(dp[i][op],dp[i-1][pre]+abs(a[i][op]-a[i-1][pre])+abs(a[i][op^1]-a[i-1][pre^1]));
		}
		printf("%lld\n",min(dp[n][0],dp[n][1]));
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
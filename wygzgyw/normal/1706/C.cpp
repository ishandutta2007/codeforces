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
const int maxn=(1e5)+10;
int T,n;
ll dp[maxn][2],a[maxn];
ll f(int x) { return max(0LL,(max(a[x-1],a[x+1])+1)-a[x]); }
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n&1) {
			ll ans=0;
			for (int i=2;i<n;i+=2) ans+=f(i);
			printf("%lld\n",ans); continue;
		}
		for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INF;
		dp[0][0]=0;
		for (int i=2;i<=n;i++) {
			chkmin(dp[i][0],dp[i-2][0]+f(i));
			chkmin(dp[i][1],dp[i-2][1]+f(i));
			if (i>2) chkmin(dp[i][1],dp[i-3][0]+f(i));
		}
		printf("%lld\n",min(dp[n-1][0],min(dp[n-1][1],dp[n-2][0])));
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
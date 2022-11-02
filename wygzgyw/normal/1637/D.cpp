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
const int INF=1e9;
const int maxn=110;
int T,n,a[maxn],b[maxn];
int presum[maxn];
int dp[maxn][maxn*maxn];
int ans;
void chkmin(int &x,int y) { if (x>y) x=y; }
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]),presum[i]=presum[i-1]+a[i]+b[i];
		for (int i=0;i<=n;i++) for (int j=0;j<=presum[n];j++) dp[i][j]=INF;
		ans=INF;
		dp[0][0]=0;
		for (int i=1;i<=n+1;i++) for (int j=0;j<=presum[i-1];j++) if (dp[i-1][j]!=INF) {
			if (i>n) { chkmin(ans,dp[i-1][j]); continue; }
			chkmin(dp[i][j+a[i]],dp[i-1][j]+j*a[i]+(presum[i-1]-j)*b[i]);
			chkmin(dp[i][j+b[i]],dp[i-1][j]+j*b[i]+(presum[i-1]-j)*a[i]);
		}
		ans*=2;
		for (int i=1;i<=n;i++) ans+=(a[i]*a[i]+b[i]*b[i])*(n-1);
		printf("%d\n",ans);
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
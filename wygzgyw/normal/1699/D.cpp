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
const int maxn=5010;
int T,n,a[maxn];
int dp[maxn],buc[maxn],mx,f[maxn][maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) buc[j]=0;
			mx=0;
			for (int j=i;j<=n;j++) {
				buc[a[j]]++;
				mx=max(mx,buc[a[j]]);
				if ((j-i+1)%2==0&&mx<=(j-i+1)/2) f[i][j]=1; else f[i][j]=0;
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++) {
			dp[i]=-1e9;
			if (1>i-1||f[1][i-1]) dp[i]=1;
			for (int j=1;j<i;j++) if (a[j]==a[i]&&(j+1>i-1||f[j+1][i-1])) dp[i]=max(dp[i],dp[j]+1);
			if (i==n||f[i+1][n]) ans=max(ans,dp[i]);
		}
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
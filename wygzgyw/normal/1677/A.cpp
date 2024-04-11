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
int T,n,p[maxn];
int pre[maxn][maxn],suf[maxn][maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) pre[i][j]=pre[i-1][j];
			for (int j=p[i]+1;j<=n;j++) pre[i][j]++;
		}
		for (int j=1;j<=n;j++) suf[n+1][j]=0;
		for (int i=n;i>=1;i--) {
			for (int j=1;j<=n;j++) suf[i][j]=suf[i+1][j];
			for (int j=p[i]+1;j<=n;j++) suf[i][j]++;
		}
		long long ans=0;
		for (int i=2;i<=n;i++) for (int j=i+1;j<=n;j++) {
			ans+=pre[i-1][p[j]]*suf[j+1][p[i]];
		}
		printf("%lld\n",ans);
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
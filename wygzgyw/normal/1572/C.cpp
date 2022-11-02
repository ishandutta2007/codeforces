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
const int maxn=3010;
int T,n;
int m,d[maxn],dp[maxn][maxn];
int lst[maxn],pre[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		m=0;
		for (int i=1;i<=n;i++) {
			int x; read(x);
			if (m&&d[m]==x);
			else d[++m]=x;
		}
		for (int i=1;i<=n;i++) lst[i]=0;
		for (int i=1;i<=m;i++) pre[i]=lst[d[i]],lst[d[i]]=i;
		for (int len=2;len<=m;len++)
		for (int i=1,j=len;j<=m;i++,j++) {
			dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			for (int k=pre[j];k>=i;k=pre[k])
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
		printf("%d\n",dp[1][m]);
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
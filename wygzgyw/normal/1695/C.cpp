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
const int INF=2e9;
const int maxn=1010;
int T,n,m;
int a[maxn][maxn],L[maxn][maxn],R[maxn][maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) read(a[i][j]);
		if ((n+m)%2==0) { puts("NO"); continue; }
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (i==1&&j==1) L[i][j]=R[i][j]=0;
				else L[i][j]=min(j==1?INF:L[i][j-1],i==1?INF:L[i-1][j]),
				R[i][j]=max(j==1?-INF:R[i][j-1],i==1?-INF:R[i-1][j]);
				L[i][j]+=a[i][j],R[i][j]+=a[i][j];
			}
		}
		int i=n,j=m;
		if (0<=R[i][j]&&0>=L[i][j]) puts("YES"); else puts("NO");
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
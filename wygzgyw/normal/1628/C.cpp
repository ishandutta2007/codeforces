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
const int maxn=1010;
int T,n,a[maxn][maxn],b[maxn][maxn],ans;
int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) read(a[i][j]);
		for (int i=0;i<=n+1;i++) for (int j=0;j<=n+1;j++) b[i][j]=0;
		ans=0;
		for (int i=1;i<=n;i++) b[1][i]=1,ans^=a[1][i];
		for (int i=2;i<=n;i++) for (int j=1;j<=n;j++) {
			if ((b[i-1][j-1]^b[i-2][j]^b[i-1][j+1])==0) b[i][j]=1,ans^=a[i][j];
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
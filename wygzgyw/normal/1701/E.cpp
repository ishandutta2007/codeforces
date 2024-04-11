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
int n,m,T;
char s[maxn],t[maxn];
int lcp[maxn][maxn];
int main() {
	read(T);
	while (T--) {
		read(m),read(n);
		scanf("%s",s+1),scanf("%s",t+1);
		for (int i=1;i<=m+1;i++) for (int j=1;j<=n+1;j++) lcp[i][j]=0;
		for (int i=m;i>=1;i--) for (int j=n;j>=1;j--)
			if (s[i]==t[j]) lcp[i][j]=lcp[i+1][j+1]+1;
		int ans=m-lcp[1][1];
		int p=1;
		for (int i=1;i<=m;i++) {
			if (p<=n&&s[i]==t[p]) p++;
			for (int j=0;j<p;j++) {
				ans=min(ans,m-lcp[i+1][j+1]+i-j+1);
			}
		}
		if (p<=n) ans=-1;
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
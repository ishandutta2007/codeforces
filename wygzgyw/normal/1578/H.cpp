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
int n,m;
char s[510];
int a[510][510],d[510][510],ans,tmp;
int main() {
	read(n),read(m);
	for (int i=1;i<=n;i++) { scanf("%s",s+1); for (int j=1;j<=m;j++) d[i][j]=(s[j]=='B'); }
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=(d[i][j]^d[i+1][j]^d[i][j+1]^d[i+1][j+1]),ans+=a[i][j];
	int all=ans;
	for (int i=1;i<n;i++) {
		for (int j=1;j<m;j++) {
			tmp=all-a[i][j]-a[i][m]-a[n][j]-a[n][m]+(a[i][j]^1)+(a[i][m]^1)+(a[n][j]^1)+(a[n][m]^1)+3;
			ans=min(ans,tmp);
		}
	}
	printf("%d\n",ans);
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
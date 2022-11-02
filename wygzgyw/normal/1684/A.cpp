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
int T,n;
bool dp[20][20];
int d[20],tot;
int main() {
	dp[1][1]=1;
	for (int i=2;i<=10;i++) for (int j=1;j<=i;j++) {
		for (int a=1;a<=i;a++) for (int b=a+1;b<=i;b++) {
			int nxt=(j==a?b:j==b?a:j);
			if (nxt<i) dp[i][j]|=dp[i-1][nxt];
		}
	}
	read(T);
	while (T--) {
		read(n);
		tot=0;
		while (n) d[++tot]=n%10,n/=10;
		int mn=1e9;
		for (int i=1;i<=tot;i++) if (dp[tot][tot-i+1]) mn=min(mn,d[i]);
		printf("%d\n",mn);
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
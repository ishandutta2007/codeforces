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
int dp[110][110][2][2][2];

int main() {
	for (int i=0;i<=100;i++) for (int j=0;j+i<=100;j++)
	for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) for (int op=0;op<=1;op++) {
		int &x=dp[i][j][a][b][op];
		if (i+j==0) {
			if (!a) x=0; else x=1; continue;
		}
		x=(op^1);
		if (i&&dp[i-1][j][a][b][op^1]==op) { x=op; continue; }
		int a2=a,b2=b;
		if (!op) a2^=1; else b2^=1;
		if (j&&dp[i][j-1][a2][b2][op^1]==op) x=op;
	}
	read(T);
	while (T--) {
		read(n);
		int a=0,b=0,x;
		for (int i=1;i<=n;i++) {
			read(x);
			if (abs(x)&1) b++; else a++;
		}
		if (dp[a][b][0][0][0]==0) puts("Alice"); else puts("Bob");
	}
	return 0;
}
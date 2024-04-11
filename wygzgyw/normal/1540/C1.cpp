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
const int mod=(1e9)+7;
int n,c[110],q,x,b[110];
int dp[110][100*100+5],s[110][100*100+5];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=2;i<=n;i++) read(b[i]),b[i]+=b[i-1];
	for (int i=2;i<=n;i++) b[i]+=b[i-1];
	read(q),read(x);
	dp[0][0]=1;
	for (int i=0;i<=n*100;i++) s[0][i]=1;
	
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=n*100;j++) {
			if (j-b[i]<x*i) dp[i][j]=0;
			else {
				dp[i][j]=s[i-1][j];
				int bd=j-c[i];
				if (bd>=1) update(dp[i][j],mod-s[i-1][bd-1]);
			}
			
			if (j) s[i][j]=s[i][j-1]; update(s[i][j],dp[i][j]);
		}
	}
	printf("%d\n",s[n][n*100]);
	
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
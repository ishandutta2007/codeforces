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
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(4e4)+10;
int T,n,N=40000;
int dp[maxn],tot,d[100];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	dp[0]=1;
	for (int i=1;i<=N;i++) {
		tot=0; int x=i;
		while (x) d[++tot]=x%10,x/=10;
		int flag=1;
		for (int j=1;j<=tot;j++) flag&=(d[j]==d[tot-j+1]);
		if (!flag) continue;
		for (int j=0;j+i<=N;j++) update(dp[j+i],dp[j]);
	}
	read(T);
	while (T--) {
		read(n);
		printf("%d\n",dp[n]);
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
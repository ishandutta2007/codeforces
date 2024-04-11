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
const int maxn=(1e5)+10;
int n,r;
int dp[maxn];
int pre[maxn],x[maxn],y[maxn],t[maxn];
void chkmax(int &x,int y) { if (x<y) x=y; }
int main() {
	read(r),read(n);
	x[0]=1,y[0]=1;
	for (int i=1;i<=n;i++) read(t[i]),read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++) {
		int fd=i; dp[i]=-1e9;
		for (int j=i-1;j>=0&&t[i]-t[j]<=2*r;j--) {
			fd=j;
			if (t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])) {
				chkmax(dp[i],dp[j]+1);
			}
		}
		if (fd) chkmax(dp[i],pre[fd-1]+1);
		pre[i]=max(pre[i-1],dp[i]);
	}
	printf("%d\n",pre[n]);
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
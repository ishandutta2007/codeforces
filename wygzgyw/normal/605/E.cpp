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
int n;
double E[maxn],p[maxn][maxn],prod[maxn];
bool vis[maxn];
int main() {
	read(n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		read(p[i][j]),p[i][j]*=0.01;
	}
	if (n==1) { puts("0"); return 0; }
	vis[n]=1;
	for (int i=1;i<n;i++) E[i]=1,prod[i]=1-p[i][n];
	for (int i=1;i<=n;i++) {
		double mn=1e18; int fd=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&E[j]/(1-prod[j])<mn) mn=E[j]/(1-prod[j]),fd=j;
		if (fd==1) break;
		vis[fd]=1;
		for (int j=1;j<=n;j++) E[j]+=E[fd]/(1-prod[fd])*p[j][fd]*prod[j],prod[j]*=(1-p[j][fd]);
	}
	printf("%.9lf\n",E[1]/(1-prod[1]));
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
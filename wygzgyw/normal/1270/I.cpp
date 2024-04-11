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
typedef unsigned long long ull;
const int mod=998244353;
int k,n;
ull a[2][600][600];
int op,X[100],Y[100],ans,m;
void solve() {
	memset(a[op^1],0,sizeof(a[op^1]));
	for (int i=0;i<n;i++) for (int j=0;j<n;j++)
		for (int l=1;l<=m;l++) a[op^1][(i+X[l])&(n-1)][(j+Y[l])&(n-1)]^=a[op][i][j];
	for (int l=1;l<=m;l++) X[l]=(X[l]<<1)&(n-1),Y[l]=(Y[l]<<1)&(n-1); op^=1;
}
int main() {
	read(k); n=(1<<k);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) read(a[op][i][j]);
	read(m); for (int i=1;i<=m;i++) read(X[i]),read(Y[i]),X[i]&=(n-1),Y[i]&=(n-1);
	while (k--) solve();
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) ans+=(a[op][i][j]>0);
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
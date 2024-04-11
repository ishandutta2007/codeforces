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
const int INF=2e9;
int T,n,m,mx[50][50],a[50][50];
int X[50][50],Y[50][50];
void insert(int x,int y,int z) {
	if (z==X[x][y]) return;
	if (X[x][y]!=-INF) Y[x][y]=z;
	else X[x][y]=z;
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) read(a[i][j]),X[i][j]=Y[i][j]=-INF;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			for (int x=0;x<=n;x++) for (int y=0;y<=m;y++) mx[x][y]=-INF;
			for (int x=i;x<=n;x++) for (int y=j;y<=m;y++) {
				mx[x][y]=max(max(a[x][y],mx[x-1][y]),mx[x][y-1]);
				insert(x-i+1,y-j+1,mx[x][y]);
			}
		}
		int ans=INF;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
			if (Y[i][j]==-INF) ans=min(ans,i*j);
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
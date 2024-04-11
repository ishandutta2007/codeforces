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
int T,n,r[50010][6];
bool cmp(int x,int y) {
	int cnt=0;
	for (int i=1;i<=5;i++) cnt+=(r[x][i]<r[y][i]);
	return cnt>=3;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) for (int j=1;j<=5;j++) read(r[i][j]);
		int mx=1;
		for (int i=2;i<=n;i++) if (cmp(i,mx)) mx=i; int flag=1;
		for (int i=1;i<=n;i++) if (i!=mx&&!cmp(mx,i)) { flag=0; break; }
		if (flag) printf("%d\n",mx);
		else puts("-1");
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
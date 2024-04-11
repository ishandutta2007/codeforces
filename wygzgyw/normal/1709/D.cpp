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
const int maxn=(2e5)+10;
int n,m,a[maxn];
int q,st[maxn][20];
int lg[maxn];
int query(int l,int r) {
	int j=lg[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}
int main() {
	read(n),read(m);
	for (int i=1;i<=m;i++) read(a[i]),st[i][0]=a[i];
	for (int i=2;i<=m;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=m;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	read(q);
	while (q--) {
		int k,x1,y1,x2,y2;
		read(x1),read(y1),read(x2),read(y2);
		read(k);
		if (abs(x1-x2)%k!=0||abs(y1-y2)%k!=0) { puts("NO"); continue; }
		int mx=x1+(n-x1)/k*k;
		if (query(min(y1,y2),max(y1,y2))>=mx) puts("NO");
		else puts("YES");
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
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
int T,n,a[maxn];
int b[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n%2==1) { puts("NO"); continue; }
		int tot=0,flag=1;
		sort(a+1,a+n+1);
		for (int i=n,j=n/2;i>=n/2+1;i--,j--) b[tot++]=a[i],b[tot++]=a[j];
		for (int i=0;i<tot;i++) flag&=((b[i]>b[(i-1+n)%n]&&b[i]>b[(i+1)%n])||(b[i]<b[(i-1+n)%n]&&b[i]<b[(i+1)%n]));
		if (flag) {
			puts("YES");
			for (int i=0;i<tot;i++) printf("%d ",b[i]); puts("");
		} else puts("NO");
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
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
int T,n,m,x;
int a,b;
int main() {
	read(T);
	while (T--) {
		read(n); a=b=0;
		for (int i=1;i<=n;i++) read(x),a=max(a,x);
		read(m);
		for (int i=1;i<=m;i++) read(x),b=max(b,x);
		if (a!=b) {
			if (a>b) puts("Alice"),puts("Alice");
			else puts("Bob"),puts("Bob");
		} else puts("Alice"),puts("Bob");
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
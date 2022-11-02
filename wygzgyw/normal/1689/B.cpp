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
int T,n;
int p[maxn],q[maxn],used[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]);
		if (n==1) { puts("-1"); continue; }
		for (int i=1;i<=n;i++) used[i]=0;
		for (int i=1;i<=n-2;i++) {
			for (int j=1;j<=n;j++) if (!used[j]&&j!=p[i]) { q[i]=j; used[j]=1; break; }
		}
		for (int i=n-1;i<=n;i++) for (int j=1;j<=n;j++) if (!used[j]) { q[i]=j; used[j]=1; break; }
		do {
			int flag=1;
			for (int i=1;i<=n;i++) flag&=(p[i]!=q[i]);
			if (flag) break;
		} while (next_permutation(q+n-1,q+n+1));
		for (int i=1;i<=n;i++) printf("%d ",q[i]); puts("");
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
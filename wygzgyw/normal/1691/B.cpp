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
int T,n;
int a[maxn],p[maxn],flag;
int main() {
	read(T);
	while (T--) {
		read(n); flag=1;
		for (int i=1;i<=n;i++) read(a[i]);
		int L=-1,R=-1;
		for (int i=1;i<=n;i++) {
			if (i==1||a[i]!=a[i-1]) L=i;
			if (i==n||a[i]!=a[i+1]) {
				R=i;
				if (L==R) { flag=0; break; }
				for (int j=L;j<R;j++) p[j]=j+1; p[R]=L;
			}
		}
		if (!flag) puts("-1");
		else {
			for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		}
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
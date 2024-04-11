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
int n,a[110],b[110],T;
int main() {
	read(T); while (T--) {
		read(n); int flag=1;
		map<int,int> M;
		for (int i=1;i<=n;i++) read(a[i]),M[a[i]]++;
		for (int i=1;i<=n;i++) read(b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		for (int i=n;i>=1;i--) {
			if (M[b[i]]>0) M[b[i]]--;
			else if (M[b[i]-1]==0) flag=0;
			else M[b[i]-1]--;
		}
		if (flag) puts("YES");
		else puts("NO");
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
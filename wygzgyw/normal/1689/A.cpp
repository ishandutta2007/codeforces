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
int T,n,m,k;
char s[110],t[110];
int main() {
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		scanf("%s",s+1);
		scanf("%s",t+1);
		sort(s+1,s+n+1);
		sort(t+1,t+m+1);
		int a=1,b=1,A=0,B=0;
		while (a<=n&&b<=m) {
			if ((s[a]<t[b]&&A<k)||B==k) {
				B=0,A++; printf("%c",s[a]); a++;
			} else {
				A=0,B++; printf("%c",t[b]); b++;
			}
		}
		puts("");
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
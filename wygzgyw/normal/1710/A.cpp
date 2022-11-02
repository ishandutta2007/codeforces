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
typedef long long ll;
int T; ll n,m,k;

int main() {
	read(T);
	while (T--) {
		read(n),read(m),read(k);
		ll s1=0,s2=0; int f1=1,f2=1;
		for (int i=1;i<=k;i++) {
			ll x; read(x);
			if (x>=n*2) s1+=x/n,f1&=(x/n==2);
			if (x>=m*2) s2+=x/m,f2&=(x/m==2);
		}
		int flag=0;
		if (s1>=m) {
			if (f1&&m%2==1); else flag=1;
		}
		if (s2>=n) {
			if (f2&&n%2==1); else flag=1;
		}
		if (flag) puts("Yes"); else puts("No");
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
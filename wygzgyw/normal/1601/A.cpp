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
int T,n;
int cnt[60];
int main() {
	read(T);
	while (T--) {
		read(n); int x; memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) {
			read(x);
			for (int j=0;j<=30;j++) if (x>>j&1) cnt[j]++;
		}
		int ans=0;
		for (int i=0;i<=30;i++) ans=__gcd(ans,cnt[i]);
		for (int i=1;i<=n;i++) if (ans%i==0) printf("%d ",i); puts("");
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
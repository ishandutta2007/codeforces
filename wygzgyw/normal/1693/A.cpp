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
const int maxn=(2e5)+10;
int T,n;
ll a[maxn],sum;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		if (sum!=0||a[1]<0) { puts("No"); continue; }
		ll A=a[1]; bool flag=1;
		if (a[1]==0) { for (int j=2;j<=n;j++) flag&=a[j]==0; if (flag) puts("Yes"); else puts("No"); continue; }
		for (int i=2;i<=n;i++) {
			A+=a[i];
			if (A<0) { flag=0; break; }
			if (A==0) { for (int j=i+1;j<=n;j++) flag&=a[j]==0; break; }
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
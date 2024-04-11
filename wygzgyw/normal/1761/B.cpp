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
int n,T;
int a[110];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n==1) { puts("1"); continue; }
		int flag=(n%2==0);
		for (int i=1;i<=n;i++) if (i%2==1) flag&=(a[i]==a[1]); else flag&=(a[i]==a[2]);
		if (flag) printf("%d\n",n/2+1); else printf("%d\n",n);
	}
	return 0;
}
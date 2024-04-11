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
int d[110],a[110];

int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(d[i]);
		for (int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
		bool flag=1;
		for (int i=2;i<=n;i++) {
			if (d[i]&&a[i-1]-d[i]>=0) { flag=0; break; }
		}
		if (!flag) puts("-1");
		else { for (int i=1;i<=n;i++) printf("%d ",a[i]); puts(""); }
	}
	return 0;
}
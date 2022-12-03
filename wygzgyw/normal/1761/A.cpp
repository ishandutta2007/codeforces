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
int T,n,a,b;

int main() {
	read(T);
	while (T--) {
		read(n),read(a),read(b);
		int flag=1;
		if (a==n&&b!=n) flag=0;
		if (b==n&&a!=n) flag=0;
		if (a==n-1||b==n-1) flag=0;
		if (a+b==n-1) flag=0;
		if (a<n&&b<n&&a+b>=n) flag=0;
		if (flag) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
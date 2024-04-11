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
int T,n,m;

int main() {
	read(T); while (T--) {
		read(n),read(m);
		if (m<n) { puts("No"); continue; }
		if (n%2==0) {
			if (m%2!=0) { puts("No"); continue; }
			puts("Yes");
			for (int i=1;i<=n-2;i++) printf("1 "); printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2); continue;
		}
		puts("Yes");
		for (int i=1;i<n;i++) printf("1 "); printf("%d\n",m-(n-1));
	}
	return 0;
}
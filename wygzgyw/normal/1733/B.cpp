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
int T,n,x,y;

int main() {
	read(T);
	while (T--) {
		read(n);
		read(x),read(y);
		if (x==0&&y==0) { puts("-1"); continue; }
		if (x&&y) { puts("-1"); continue; }
		x+=y;
		if ((n-1)%x!=0) { puts("-1"); continue; }
		for (int i=1,now=2;i<=(n-1)/x;i++,now+=x) {
			for (int j=1;j<=x;j++) printf("%d ",now);
		} puts("");
	}
	return 0;
}
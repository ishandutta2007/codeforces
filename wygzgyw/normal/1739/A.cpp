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
	read(T);
	while (T--) {
		read(n),read(m);
		int X=1,Y=1;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			bool fd=0;
			for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) for (int c=0;c<=1;c++) {
				int x=i,y=j;
				int A,B; if (!c) A=1,B=2; else A=2,B=1;
				if (a==0) A=-A; if (b==0) B=-B;
				x+=A,y+=B;
				if (1<=x&&x<=n&&1<=y&&y<=m) { fd=1; break; }
			}
			if (!fd) X=i,Y=j;
		}
		printf("%d %d\n",X,Y);
	}
	return 0;
}
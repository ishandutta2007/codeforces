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
int T,x[3],y[3];
int a,b,n;
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=0;i<3;i++) read(x[i]),read(y[i]);
		read(a),read(b);
		int xx,yy;
		for (int i=0;i<3;i++) {
			int flag=1;
			for (int j=0;j<3;j++) if (i!=j) flag&=(x[i]==x[j]||y[i]==y[j]);
			if (flag) { xx=x[i],yy=y[i]; break; }
		}
		if ((xx==1||xx==n)&&(yy==1||yy==n)) {
			if (a==xx||b==yy) puts("YES"); else puts("NO");
		} else if ((a+b)%2!=(xx+yy)%2) puts("YES");
		else if (a%2==xx%2) puts("YES"); else puts("NO");
	}
	return 0;
}
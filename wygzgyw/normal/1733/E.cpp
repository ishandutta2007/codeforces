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
const int maxn=125;
int T;
ll t;
int x,y;
ll d[maxn][maxn];

int main() {
	read(T);
	while (T--) {
		read(t),read(x),read(y);
		if (t<x+y) { puts("NO"); continue; }
		memset(d,0,sizeof(d));
		d[0][0]=t-x-y;
		for (int i=0;i<120;i++) for (int j=0;j<120;j++) {
			d[i][j+1]+=(d[i][j]+1)/2;
			d[i+1][j]+=d[i][j]/2;
		}
		int a=0,b=0,flag=0;
		while (a+b<x+y) {
			if (d[a][b]%2==0) b++; else a++;
			if (a==120||b==120) { flag=1; break; }
		}
		if (!flag&&a==x&&b==y) puts("YES"); else puts("NO");
	}
	return 0;
}
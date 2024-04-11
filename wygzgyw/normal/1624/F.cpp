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
const int flag=0;
int n,x;
int l,r;
int query(int c) {
	printf("+ %d\n",c); fflush(stdout);
	if (flag) { x+=c; return x/n; }
	scanf("%d",&c); return c;
}
int main() {
	scanf("%d",&n); if (flag) scanf("%d",&x);
	l=1,r=n-1; int lst=0,tmp;
	while (l<r) {
		int R=(lst+1)*n-1;
		int c=((R-l)+(R-r)+1)/2;
		tmp=query(c); lst=tmp;
		l+=c,r+=c;
		l=max(l,tmp*n),r=min(r,(tmp+1)*n-1);
	}
	printf("! %d\n",l); fflush(stdout);
	if (flag) printf("! %d\n",x);
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
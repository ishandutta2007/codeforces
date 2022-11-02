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
int n,x[6010],y[6010];
ll cnt[2][2],ans;
ll C(ll n) { return n*(n-1)/2; }
int gcd(int x,int y) {
	x=abs(x),y=abs(y);
	if (x||y) return 1; return 0;
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		read(x[i]),read(y[i]),x[i]/=2,y[i]/=2;
		cnt[x[i]%2][y[i]%2]++;
	}
	for (int x1=0;x1<=1;x1++) for (int y1=0;y1<=1;y1++)
	for (int x2=0;x2<=1;x2++) for (int y2=0;y2<=1;y2++)
	for (int x3=0;x3<=1;x3++) for (int y3=0;y3<=1;y3++) {
		if ((gcd(x1-x2,y1-y2)+gcd(x1-x3,y1-y3)+gcd(x2-x3,y2-y3))%2==0) ans+=cnt[x1][y1]*cnt[x2][y2]*cnt[x3][y3];
	}
	ans-=C(n)*3*2+n;
	printf("%lld\n",ans/6);
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
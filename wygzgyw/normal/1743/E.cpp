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
const ll INF=1e18;
int p1,p2;
ll t1,t2;
int h,s;
ll f[5010],g[5010];
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
	read(p1),read(t1);
	read(p2),read(t2);
	read(h),read(s);
	for (int i=1;i<=h;i++) f[i]=g[i]=INF;
	for (int a=0;a<=h;a++) for (int b=0;b<=h;b++) {
		chkmin(f[min(h,a*(p1-s)+b*(p2-s))],max(t1*a,t2*b));
		chkmin(g[min(h,a*(p1-s)+b*(p2-s)+(p1+p2-s))],max(t1*(a+1),t2*(b+1)));
	}
	for (int a=0;a<=h;a++) for (int b=0;b<=h;b++) chkmin(f[min(h,a+b)],f[a]+g[b]);
	printf("%lld\n",f[h]);
	return 0;
}
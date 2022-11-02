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
const int maxn=(1e5)+10;
int n,q,	a[maxn],b[maxn],lg[maxn];
ll pre[maxn],mn[maxn][20],mx[maxn][20];
ll queryMN(int l,int r) { int j=lg[r-l+1]; return min(mn[l][j],mn[r-(1<<j)+1][j]); }
ll queryMX(int l,int r) { int j=lg[r-l+1]; return max(mx[l][j],mx[r-(1<<j)+1][j]); }
int main() {
	read(n); read(q); int l,r;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i]-b[i],mn[i][0]=mx[i][0]=pre[i];
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n;j++)
		mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]),
		mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
	while (q--) {
		read(l),read(r);
		ll t1=queryMX(l,r),t2=queryMN(l,r);
		if (pre[r]-pre[l-1]!=0||t1-pre[l-1]>0) puts("-1");
		else printf("%lld\n",t1-t2);
	}
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
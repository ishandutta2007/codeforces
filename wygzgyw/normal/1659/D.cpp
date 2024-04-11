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
const int maxn=(2e5)+10;
int T,n,c[maxn],a[maxn];
namespace BIT {
	int tr[maxn];
	void clear() { for (int i=1;i<=n;i++) tr[i]=0; }
	void add(int x,int delta) {
		for (;x<=n;x+=x&(-x)) tr[x]+=delta;
	}
	int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
};
int main() {
	read(T);
	while (T--) {
		read(n);
		int flag=1;
		for (int i=1;i<=n;i++) read(c[i]),flag&=(c[i]==0);
		BIT::clear();
		if (flag) { for (int i=1;i<=n;i++) printf("0 "); puts(""); continue; }
		ll sum=0;
		for (int i=1;i<=n;i++) a[i]=0,sum+=c[i]; sum/=n;
		for (int i=n;i>=1;i--) {
			if (!sum) break;
			if (i==1) { a[i]=sum; break; }
			int now=c[i]-BIT::query(i);
			BIT::add(i-sum+1,1);
			if (now==1) a[i]=0; else a[i]=1,sum--;
		}
		for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
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
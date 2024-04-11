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
const int maxn=(5e5)+10;
int T,n,c[maxn],p[maxn],id[maxn];
namespace BIT {
	int tr[maxn];
	void clear() { for (int i=1;i<=n;i++) tr[i]=0; }
	void add(int x,int delta=1) { for (;x<=n;x+=x&(-x)) tr[x]+=delta; }
	int query(int x) {
		int res=0;
		for (;x;x-=x&(-x)) res+=tr[x];
		return res;
	}
};
bool cmp(int x,int y) { return c[x]>c[y]; }
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]),c[i]=i-2*p[i]+1,id[i]=i;
		sort(id+1,id+n+1,cmp);
		BIT::clear(); ll all=0;
		for (int i=n;i>=1;i--) all+=BIT::query(p[i]),BIT::add(p[i]);
		printf("%lld ",all);
		ll tmp=0;
		for (int i=1;i<=n;i++) {
			tmp-=c[id[i]];
			printf("%lld ",all+tmp-(ll)i*(i-1)/2);
		} puts("");
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
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
const int maxn=(2e5)+10;
int T,n,m,cnt[maxn];
bool check(int mid) {
	long long buf=0;
	for (int i=1;i<=n;i++) {
		if (cnt[i]<=mid) buf+=(mid-cnt[i])/2;
		else buf-=(cnt[i]-mid);
	}
	return buf>=0;
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) cnt[i]=0;
		int x; for (int i=1;i<=m;i++) read(x),cnt[x]++;
		int l=1,r=2*m,res,mid;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) res=mid,r=mid-1; else l=mid+1;
		}
		printf("%d\n",res);
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
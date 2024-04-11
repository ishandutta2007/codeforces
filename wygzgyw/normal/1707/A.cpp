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
const int maxn=(1e5)+10;
int T;
int n,q,s[maxn],a[maxn];
bool check(int mid) {
	int now=q;
	for (int i=1;i<=mid;i++) {
		if (a[i]<=q) s[i]=1; else s[i]=0;
	}
	for (int i=mid+1;i<=n;i++) {
		s[i]=1;
		if (a[i]>now) now--;
	}
	return now>=0;
}
int main() {
	read(T);
	while (T--) {
		read(n),read(q);
		for (int i=1;i<=n;i++) read(a[i]);
		int l=0,r=n,res,mid;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) res=mid,r=mid-1;
			else l=mid+1;
		}
		check(res);
		for (int i=1;i<=n;i++) printf("%d",s[i]); puts("");
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
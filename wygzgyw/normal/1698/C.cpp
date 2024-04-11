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
int n,m,T;
ll a[maxn],b[maxn];
bool chk(ll x) {
	int y=lower_bound(a+1,a+n+1,x)-a;
	return y<=n&&a[y]==x;
}
bool solve() {
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) for (int k=j+1;k<=n;k++)
		if (!chk(a[i]+a[j]+a[k])) return 0;
	return 1;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		int cnt=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) cnt++;
		}
		sort(a+1,a+n+1);
		int tmp=min(cnt,3); m=0;
		for (int i=1;i<=n;i++) {
			if (a[i]) b[++m]=a[i];
			else if (tmp>0) tmp--,b[++m]=a[i];
		}
		n=m; for (int i=1;i<=m;i++) a[i]=b[i];
		if (n>10) { puts("NO"); continue; }
		if (solve()) puts("YES"); else puts("NO");
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
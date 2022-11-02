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
const int maxn=(2e6)+10;
const int N=1e6;
int T,n,a[20],b[20],lg[1024],sum[1024];
int tim,vis[maxn];
bool solve() {
	for (int t1=0;t1<(1<<n);t1++) {
		for (int i=1;i<=n;i++) if (t1&(1<<(i-1))) b[i]=a[i]; else b[i]=-a[i];
		tim++;
		for (int t2=0;t2<(1<<n);t2++) {
			if (t2) sum[t2]=sum[t2-(t2&(-t2))]+b[lg[t2&(-t2)]];
			if (vis[sum[t2]+N]==tim) return 1;
			vis[sum[t2]+N]=tim;
		}
	} return 0;
}
int main() {
	for (int i=1;i<=10;i++) lg[1<<(i-1)]=i;
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
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
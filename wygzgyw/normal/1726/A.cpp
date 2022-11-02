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
const int maxn=2010;
int T,n,a[maxn];

int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		int ans=a[n]-a[1];
		for (int i=1;i<n;i++) ans=max(ans,a[n]-a[i]);
		for (int i=2;i<=n;i++) ans=max(ans,a[i]-a[1]);
		for (int i=1;i<n;i++) ans=max(ans,a[i]-a[i+1]);
		printf("%d\n",ans);
	}
	return 0;
}
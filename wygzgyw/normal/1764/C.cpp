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
int T,n;
int a[maxn],d[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);
		int tot=0;
		for (int i=1;i<=n;i++) {
			if (i>1&&a[i]==a[i-1]) d[tot]++; else d[++tot]=1;
		}
		ll ans=0;
		if (tot==1) ans=n/2;
		else {
			int pre=0;
			for (int i=1;i<=tot;i++) pre+=d[i],ans=max(ans,(ll)pre*(n-pre));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
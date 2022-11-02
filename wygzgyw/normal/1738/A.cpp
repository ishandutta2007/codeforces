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
int a[maxn],b[maxn];
int d[maxn],t1,e[maxn],t2;
ll ans;

int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		t1=t2=0; ans=0;
		for (int i=1;i<=n;i++) {
			ans+=b[i];
			if (!a[i]) d[++t1]=b[i]; else e[++t2]=b[i];
		}
		sort(d+1,d+t1+1),reverse(d+1,d+t1+1);
		sort(e+1,e+t2+1),reverse(e+1,e+t2+1);
		if (t1==t2) {
			ans=ans*2-min(d[t1],e[t2]);
		} else {
			int m=min(t1,t2);
			for (int i=1;i<=m;i++) ans+=d[i]+e[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
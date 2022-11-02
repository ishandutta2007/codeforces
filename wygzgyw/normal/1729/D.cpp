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
int T,n;
ll a[maxn],d[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) {
			ll x; read(x); x-=a[i];
			d[i]=x;
		}
		sort(d+1,d+n+1);
		int ans=0;
		for (int i=n,j=1;i>j;i--) {
			while (j+1<i&&d[j]+d[i]<0) j++;
			if (j<i&&d[j]+d[i]>=0) ans++,j++; else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
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
int T,n,k;
ll s[maxn],a[maxn];

int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=n-k+1;i<=n;i++) read(s[i]);
		int flag=1;
		if (n==k) {
			for (int i=1;i<=n;i++) a[i]=s[i]-s[i-1];
			for (int i=2;i<=n;i++) flag&=a[i-1]<=a[i];
			if (flag) puts("YES"); else puts("NO"); continue;
		}
		for (int i=n-k+2;i<=n;i++) a[i]=s[i]-s[i-1];
		k=n-k+1;
		for (int i=1;i<=k;i++) {
			a[i]=abs(s[k])/k;
		}
		ll rst=abs(s[k])-abs(s[k])/k*k;
		for (int i=k;i>=k-rst+1;i--) a[i]++;
		if (s[k]<0) {
			for (int i=1;i<=k;i++) a[i]*=-1;
			reverse(a+1,a+k+1);
		}
		for (int i=2;i<=n;i++) flag&=a[i-1]<=a[i];
		if (flag) puts("YES"); else puts("NO"); continue;
	}
	return 0;
}
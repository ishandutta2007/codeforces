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

int T,n;
ll x,ans;

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		ll a1; ans=0;
		for (int i=1;i<=n;i++) {
			read(x);
			if (i==1) { a1=x; continue; }
			ll bd=a1*2-1;
			if (x>bd) {
				if (x%bd==0) ans+=x/bd-1; else ans+=x/bd;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
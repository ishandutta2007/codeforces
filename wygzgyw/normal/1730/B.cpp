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
ll x[maxn],t[maxn];
bool check(ll mid,bool flag=0) {
	ll L=-1e9,R=1e9;
	for (int i=1;i<=n;i++) {
		ll l=x[i]-(mid-t[i]);
		ll r=x[i]+(mid-t[i]);
		L=max(L,l),R=min(R,r);
	}
	if (flag) {
		if (L%2==0) printf("%lld\n",L/2);
		else printf("%lld.5\n",L/2);
	}
	return L<=R;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		ll l=0,r=1e9,mid,res=-1;
		for (int i=1;i<=n;i++) read(x[i]);
		for (int i=1;i<=n;i++) read(t[i]),x[i]*=2,t[i]*=2,l=max(l,t[i]);
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid)) res=mid,r=mid-1; else l=mid+1;
		}
		assert(res!=-1);
		check(res,1);
	}
	return 0;
}
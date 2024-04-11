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
int T;
ll l,r;
ll calc(ll bd,int k) {
	ll l=1,r=2e9,mid,res=0;
	while (l<=r) {
		mid=(l+r)>>1;
		if (mid*(mid+k)<=bd) res=mid,l=mid+1; else r=mid-1;
	} return res;
}
ll solve(ll r) {
	return calc(r,0)+calc(r,1)+calc(r,2);
}
int main() {
	read(T);
	while (T--) {
		read(l),read(r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
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
int n;
ll a[maxn],m;
ll all;
ll f(ll x,ll y) {
	ll z=x/y,c=x%y;
	return z*z*(y-c)+(z+1)*(z+1)*c;
}
ll calc(ll mid) {
	ll Res=0;
	ll M=0;
	for (int i=1;i<=n;i++) if (a[i]>1&&a[i]*a[i]-f(a[i],2)>=mid) {
		ll l=1,r=a[i]-1,Mid,res=1;
		while (l<=r) {
			Mid=(l+r)>>1;
			if (f(a[i],Mid)-f(a[i],Mid+1)>=mid) res=Mid,l=Mid+1; else r=Mid-1;
		}
		Res+=a[i]*a[i]-f(a[i],res+1);
		M+=a[i];
	}
	return Res;
}
ll calc2(ll mid) {
	ll Res=0;
	for (int i=1;i<=n;i++) if (a[i]>1&&a[i]*a[i]-f(a[i],2)>=mid) {
		ll l=1,r=a[i]-1,Mid,res=1;
		while (l<=r) {
			Mid=(l+r)>>1;
			if (f(a[i],Mid)-f(a[i],Mid+1)>=mid) res=Mid,l=Mid+1; else r=Mid-1;
		}
		Res+=res;
	}
	return Res;
}
ll Up(ll x,ll y) { if (x%y==0) return x/y; return x/y+1; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=n;i>=1;i--) a[i]-=a[i-1],all+=a[i]*a[i];
	read(m);
	if (all<=m) { puts("0"); return 0; }
	ll l=0,r=1e18,mid,res=-1;
	while (l<=r) {
		mid=(l+r)>>1;
		if (all-calc(mid)<=m) res=mid,l=mid+1; else r=mid-1;
	}
	ll ans=calc2(res+1);
	all-=calc(res+1);
	ans+=Up(all-m,res);
	printf("%lld\n",ans);
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
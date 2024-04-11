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
const int maxn=35010;
int n;
ll a[maxn],l[maxn],r[maxn];
ll solve(ll v) {
	priority_queue<ll> x;
	priority_queue<ll,vector<ll>,greater<ll> > y;
	for (int i=0;i<=n;i++) x.push(v),y.push(v);
	ll dx=0,dy=0,res=0;
	for (int i=1;i<=n;i++) {
		dx+=a[i]-r[i],dy+=a[i]-l[i];
		ll tmp=y.top()+dy;
		if (tmp<0) res-=tmp,y.pop(),x.push(tmp-dx),y.push(-dy); else x.push(-dx);
		tmp=x.top()+dx;
		if (tmp>0) res+=tmp,x.pop(),y.push(tmp-dy),x.push(-dx); else y.push(-dy);
	}
	while (!x.empty()&&x.top()+dx>v) res+=x.top()+dx-v,x.pop();
	while (!y.empty()&&y.top()+dy<v) res+=v-y.top()-dy,y.pop();
	return res;
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),read(l[i]),read(r[i]);
	ll l=-1e10,r=1e10,mid;
	while (r-l>5) {
		mid=(l+r)>>1;
		if (solve(mid)<solve(mid+1)) r=mid; else l=mid;
	}
	ll ans=1e18;
	for (ll i=l;i<=r;i++) ans=min(ans,solve(i)); printf("%lld\n",ans);
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
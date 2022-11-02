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
const int maxn=3010;
int n;
ll k,a[maxn],s[maxn];
int cnt[maxn],CNT[maxn];
ll suf[maxn],ans;
void solve() {
	for (int i=1;i<=n;i++) {	
		cnt[i]=cnt[i-1];
		if (!a[i]) cnt[i]++;
		s[i]=s[i-1]+a[i];
	}
	ll l=s[n]-k*cnt[n],r=s[n]+k*cnt[n];
	if (l<=0&&0<=r); else { puts("-1"); exit(0); }
	for (int i=n;i>=1;i--) {
		suf[i]=suf[i+1]+a[i];
		CNT[i]=CNT[i+1]+(!a[i]);
	}
	for (int i=0;i<=n;i++) for (int j=i+1;j<=n;j++) {
		ll a=s[i]-k*cnt[i];
		ll b=s[i]+k*cnt[i];
		ll l=(s[j]-s[i])-k*(cnt[j]-cnt[i]);
		ll r=(s[j]-s[i])+k*(cnt[j]-cnt[i]);
		l*=-1,r*=-1,swap(l,r);
		ll L=-suf[j+1]-k*CNT[j+1];
		ll R=-suf[j+1]+k*CNT[j+1];
		vector<ll> V;
		V.push_back(a),V.push_back(b);
		V.push_back(l+L),V.push_back(r+R);
		V.push_back(l+R),V.push_back(r+L);
		for (ll &x : V) if (a<=x&&x<=b) {
			ll v1=max(L,x-r),v2=min(R,x-l);
			if (v1<=v2) ans=max(ans,x-v1);
		}
	}
}
int main() {
	read(n); read(k);
	for (int i=1;i<=n;i++) {
		read(a[i]);
	}
	solve();
	for (int i=1;i<=n;i++) a[i]=-a[i];
	solve();
	printf("%lld\n",ans+1);
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
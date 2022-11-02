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
ll a[110],b[110];
bool solve(ll mid) {
	a[100]+=mid;
	ll s1=0,s2=0;
	ll N=(n+mid)-(n+mid)/4,now=0;
	for (int i=100;i>=1;i--) {
		if (now+a[i]<=N) s1+=a[i]*i,now+=a[i];
		else { s1+=(N-now)*i; break; }
	}
	now=0;
	for (int i=100;i>=1;i--) {
		if (now+b[i]<=N) s2+=b[i]*i,now+=b[i];
		else { s2+=(N-now)*i; break; }
	}
	a[100]-=mid;
	return s1>=s2;
}
int main() {
	read(T);
	while (T--) {
		read(n); int x;
		memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++) read(x),a[x]++;
		for (int i=1;i<=n;i++) read(x),b[x]++;
		ll l=0,r=1e9,mid,res=-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (solve(mid)) res=mid,r=mid-1; else l=mid+1;
		}
		printf("%lld\n",res);
	}
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
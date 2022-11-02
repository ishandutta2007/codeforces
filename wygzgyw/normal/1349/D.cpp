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
const int mod=998244353;
const int maxn=(3e5)+10;
int n,a[maxn],m;
int f[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ans;
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),m+=a[i];
	f[0]=n-1;
	for (int i=1;i<m;i++) {
		f[i]=((ll)i*ksm(m,mod-2)%mod*f[i-1]%mod+1)*m%mod*(n-1)%mod*ksm(m-i,mod-2)%mod;
	}
	for (int i=m;i>=0;i--) update(f[i],f[i+1]);
	for (int i=1;i<=n;i++) update(ans,f[a[i]]);
	update(ans,mod-(ll)f[0]*(n-1)%mod);
	ans=(ll)ans*ksm(n,mod-2)%mod;
	printf("%d\n",ans);
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
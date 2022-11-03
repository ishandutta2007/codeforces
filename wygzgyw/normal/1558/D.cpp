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
const int maxn=(5e5)+10;
int T,n,m,x[maxn],y[maxn];
int tr[maxn],rem[maxn],flag[maxn];
void add(int x,int delta) {
	for (;x<maxn;x+=x&(-x)) tr[x]+=delta;
}
int query(int k) {
	int res=0;
	for (int i=18;i>=0;i--)
		if (res+(1<<i)<=n+1&&k>tr[res+(1<<i)]) res+=(1<<i),k-=tr[res];
	return res+1;
}
ll fac[maxn],inv[maxn],ifac[maxn];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main() {
	read(T); init();
	for (int i=1;i<maxn;i++) add(i,1);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=m;i++) read(x[i]),read(y[i]);
		int ans=0;
		for (int i=m;i>=1;i--) {
			rem[i]=query(y[i]);
			add(rem[i],-1);
			flag[rem[i]]=1;
			if (!flag[rem[i]+1]) ans++;
		}
		printf("%lld\n",C(n*2-1-ans,n));
		for (int i=1;i<=m;i++) add(rem[i],1),flag[rem[i]]=0;
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
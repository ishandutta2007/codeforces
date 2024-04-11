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
const int mod=(1e9)+7;
const int maxn=(3e6)+10;
int n,q;
ll ans[maxn][3];
ll fac[maxn],inv[maxn],ifac[maxn];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main() {
	read(n),read(q);
	init();
	ans[3*n][0]=1;
	for (int i=3*n-1;i>=0;i--) {
		ans[i][0]=(ans[i+2][0]+ans[i+2][2]-C(2,i+2)+C(n*3+2,i+2)-2*(ans[i+2][1]+C(n*3+1,i+2)));
		ans[i][1]=(ans[i+2][1]+ans[i+2][0]-C(0,i+2)-2*ans[i+2][2]);
		ans[i][2]=(ans[i+2][2]+ans[i+2][1]-C(1,i+2)+C(n*3+1,i+2)-2*ans[i+2][0]);
		for (int j=0;j<=2;j++) ans[i][j]=(ans[i][j]%mod+mod)%mod;
		
	}
	int x;
	while (q--) read(x),printf("%lld\n",ans[x][0]);
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
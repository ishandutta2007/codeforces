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
int T,n;
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn];
void init() {
	jc[0]=jc[1]=ivjc[0]=ivjc[1]=1;
	for(int i=2;i<maxn;++i) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=1;i--) ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
}
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int f[maxn],g[maxn];
int main() {
	read(T); init();
	while (T--) {
		read(n);
		int ans=0;
		
		f[0]=f[1]=1;
		for (int i=2;i<=n;i++) f[i]=((ll)f[i-2]*(i-1)+f[i-1])%mod;
		
		g[0]=1;
		for (int i=2;i<=n;i+=2) g[i]=(ll)g[i-2]*(i-1)%mod;
		
		for (int i=0,t=1;i*4<=n;i++) {
			update(ans,(ll)C(n-i*2,i*2)*f[n-i*4]%mod*t%mod*g[i*2]%mod),t=(ll)t*2%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
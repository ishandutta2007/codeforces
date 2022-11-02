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
typedef unsigned long long ull;
typedef long long ll;
const int mod=998244353;
const int maxn=(1<<16);
int n,k;
int cnt;
ull ans[maxn];
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
int main() {
	read(n),read(k);
	init();
	int l=n,r=n+1,t=1;
	for (int x=0;x<=k;x++) {
		int L=n-x,R=n-2*x+1;
		if (R<=0) break;
		while (l>L) t=(ll)t*ksm(l,mod-2)%mod,l--;
		while (r>R) r--,t=(ll)t*r%mod;
//		printf("%d %d %d\n",L,R,t);
		int t2=t;
		for (int y=0;y<=k-x&&y<=n-2*x;y++) {
			if (y) t2=(ll)t2*(n-2*x-y+1)%mod;
			ans[x+y]+=(ull)t2*ivjc[x]%mod*ivjc[y];
			if (ans[x+y]>7e18) ans[x+y]%=mod;
		}
	}
	for (int i=1;i<=k;i++) printf("%llu ",ans[i]%mod); puts("");
	return 0;
}
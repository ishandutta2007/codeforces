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
const int maxn=2010;
int f[55][2010][55];
int jc[maxn],ivjc[maxn];
int n,k,S,a[55];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
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
	for (int i=1;i<=n;i++) read(a[i]),S+=a[i];
	init();
	int now=0;
	f[0][0][0]=1;
	for (int i=1;i<=n;i++) {
		for (int l=0;l*k<=a[i];l++) {
			int t=(ll)(a[i]-l*k)*ksm(S,mod-2)%mod;
			int c1=(ll)ivjc[l]*ksm(t,l)%mod;
			int c2=(l==0?0:(ll)ivjc[l-1]*ksm(t,l-1)%mod);
			if (l&1) c1=mod-c1,c2=mod-c2;
			if (a[i]==k&&l==1) c2=0;
			for (int x=0;x<=now;x++) for (int y=0;y<=i;y++) if (f[i-1][x][y]) {
				update(f[i][x+l][y],(ll)c1*f[i-1][x][y]%mod);
				update(f[i][x+l][y+1],(ll)c2*f[i-1][x][y]%mod);
			}
		}
		now+=a[i];
	}
	int ans=0;
	for (int l=1;l<=S;l++) for (int v=0;v<=n;v++) if (f[n][l][v]) {
		int tmp=(ll)f[n][l][v]*jc[l-v]%mod*ksm(ksm(k*l,mod-2),l-v+1)%mod*ksm(S,l-v+1)%mod;
		update(ans,tmp);
	}
	ans=(mod-ans)%mod;
	printf("%d\n",ans);
	return 0;
}
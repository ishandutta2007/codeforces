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
const int maxn=(6e5)+10;
int n,a[maxn];
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
int cnt[maxn][2],b[maxn];
int main() {
	read(n); init();
	int mn=1e9,mx=0;
	for (int i=1;i<=n;i++) read(a[i]),mn=min(mn,a[i]),mx=max(mx,a[i]);
	if (mx==mn) { printf("%d\n",jc[n]); return 0; }
	int T=mn+n-1; if (mx>T) { puts("0"); return 0; }
	for (int i=1;i<=n;i++) read(b[i]),cnt[a[i]][b[i]]++;
	int ans=(ll)C(n,cnt[T][1])*jc[cnt[T][1]]%mod;
	int pre=0;
	for (int i=mn;i<=mx;i++) {
		if (cnt[i][0]&&pre<T-i) { puts("0"); return 0; }
		pre+=cnt[i][0];
		ans=(ll)ans*jc[cnt[i][0]]%mod;
		if (i<T&&cnt[i][1]&&(cnt[i][1]>1||pre<i-mn)) { puts("0"); return 0; }
		pre+=cnt[i][1];
	}
	printf("%d\n",ans);
	return 0;
}
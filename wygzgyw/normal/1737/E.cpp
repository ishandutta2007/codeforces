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
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
const int maxn=(1e6)+10;
int T,n;
int ans[maxn];
int suf[maxn];
int f[maxn],ivmi[maxn];
int main() {
	int iv2=(mod+1)/2;
	ivmi[0]=1; for (int i=1;i<maxn;i++) ivmi[i]=(ll)ivmi[i-1]*iv2%mod;
	read(T);
	while (T--) {
		read(n);
		suf[n+1]=0;
		for (int i=n;i>=1;i--) {
			if (i==n) f[i]=ivmi[(n-1)/2];
			else f[i]=ivmi[(i+1)/2];
			ans[i]=(ll)f[i]*(1-(i*2<=n?suf[i*2]:0)+mod)%mod;
			suf[i]=(suf[i+1]+ans[i])%mod;
		}
		for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
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
const int maxn=(5e5)+10;
const int mod=998244353;
int T,n,cnt;
int a[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int dp[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int C2(int x) { return ((ll)x*(x-1)/2)%mod; }
int main() {
	read(T);
	while (T--) {
		read(n); cnt=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (a[i]==0) cnt++;
		}
		int all=ksm(C2(n),mod-2);
		int bd=0;
		for (int i=1;i<=cnt;i++) if (a[i]) bd++;
		for (int i=1;i<=bd;i++) {
			int p1,p2;
			p2=(ll)i*i%mod*all%mod;
			p1=(1-p2+mod)%mod;
			dp[i]=((ll)dp[i-1]*p2+1)%mod*ksm(p2,mod-2)%mod;
		}
		printf("%d\n",dp[bd]);
	}
	return 0;
}
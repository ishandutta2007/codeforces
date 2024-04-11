#include<cstdio>
#include<algorithm>
using namespace std;
const int G = 3;
const int MAXN = 4*int(1E6);
const int MOD = 998244353;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int fct[MAXN + 5], inv[MAXN + 5];
void init() {
	fct[0] = 1;
	for(int i=1;i<=MAXN;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
	inv[MAXN] = pow_mod(fct[MAXN], MOD-2);
	for(int i=MAXN-1;i>=0;i--)
		inv[i] = 1LL*inv[i+1]*(i+1)%MOD;
}
void ntt(int A[], int n, int type) {
	for(int i=0,j=0;i<n;i++) {
		if( i < j ) swap(A[i], A[j]);
		for(int l=(n>>1);(j^=l)<l;l>>=1);
	}
	for(int s=2;s<=n;s<<=1) {
		int t = (s >> 1);
		int u = (type == 1) ? (pow_mod(G, (MOD-1)/s)) : (pow_mod(G, (MOD-1)-(MOD-1)/s));
		for(int i=0;i<n;i+=s) {
			for(int p=1,j=0;j<t;j++,p=1LL*p*u%MOD) {
				int x = A[i+j], y = 1LL*A[i+j+t]*p%MOD;
				A[i+j] = (x + y)%MOD, A[i+j+t] = (x + MOD - y)%MOD;
			}
		}
	}
	if( type == -1 ) {
		int inv = pow_mod(n, MOD-2);
		for(int i=0;i<n;i++)
		A[i] = 1LL*A[i]*inv%MOD;
	}
}
int f[MAXN + 5], g[MAXN + 5];
int main() {
	init();
	int n; scanf("%d", &n);
	int ans = fct[n];/*
	for(int i=1;i<=n;i++) {
		for(int j=i;j<n;j++) {
			ans = (ans + 1LL*fct[j]*inv[i-1]%MOD*inv[j-i]%MOD*(n-i-1)%MOD*fct[n-i-1]%MOD)%MOD;
		}
	}*/
	for(int i=0;i<=n;i++) {
		if( i ) f[i] = 1LL*inv[i-1]*(n-i-1)%MOD*fct[n-i-1]%MOD;
		g[i] = inv[i];
	}
	int len; for(len = 1;len < (n<<1);len <<= 1);
	ntt(f, len, 1), ntt(g, len, 1);
	for(int i=0;i<len;i++)
		g[i] = 1LL*g[i]*f[i]%MOD;
	ntt(g, len, -1);
	for(int i=1;i<n;i++)
		ans = (ans + 1LL*fct[i]*g[i]%MOD)%MOD;
	printf("%d\n", ans);
}
#include<cstdio>
#include<algorithm>
using namespace std;
const int G = 3;
const int MOD = 998244353;
const int MAXN = 400000;
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
void ntt(int *A, int n, int type) {
	for(int i=0,j=0;i<n;i++) {
		if( i < j ) swap(A[i], A[j]);
		for(int l=(n>>1);(j^=l)<l;l>>=1);
	}
	for(int s=2;s<=n;s<<=1) {
		int t = (s>>1);
		int u = (type == 1) ? pow_mod(G, (MOD-1)/s) : pow_mod(G, (MOD-1)-(MOD-1)/s);
		for(int i=0;i<n;i+=s) {
			int p = 1;
			for(int j=0;j<t;j++,p=1LL*p*u%MOD) {
				int x = A[i+j], y = 1LL*A[i+j+t]*p%MOD;
				A[i+j] = (x + y)%MOD, A[i+j+t] = (x + MOD - y)%MOD;
			}
		}
	}
	if( type == -1 ) {
		int k = 1LL*fct[n-1]*inv[n]%MOD;
		for(int i=0;i<n;i++)
			A[i] = 1LL*A[i]*k%MOD;
	}
}
void init() {
	fct[0] = 1;
	for(int i=1;i<=MAXN;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
	inv[MAXN] = pow_mod(fct[MAXN], MOD - 2);
	for(int i=MAXN-1;i>=0;i--)
		inv[i] = 1LL*inv[i+1]*(i+1)%MOD;
}
int comb(int n, int m) {
	return 1LL*fct[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int tmp1[MAXN + 5], tmp2[MAXN + 5], tmp3[MAXN + 5];
void sterling1(int *A, int n) {
	if( !n ) {
		A[0] = 1;
		return ;
	}
	int m = n/2, pw = 1, len;
	sterling1(A, m);
	for(len = 1;len <= n;len <<= 1);
	for(int i=0;i<=m;i++) tmp1[m - i] = 1LL*fct[i]*A[i]%MOD;
	for(int i=0;i<=m;i++) tmp2[i] = 1LL*inv[i]*pw%MOD, pw=1LL*pw*m%MOD;
	for(int i=m+1;i<len;i++) tmp1[i] = tmp2[i] = 0;
	ntt(tmp1, len, 1), ntt(tmp2, len, 1);
	for(int i=0;i<len;i++) tmp1[i] = 1LL*tmp1[i]*tmp2[i]%MOD;
	ntt(tmp1, len, -1);
	for(int i=0;i<=m;i++) tmp3[m - i] = 1LL*tmp1[i]*inv[m - i]%MOD;
	for(int i=0;i<=m;i++) tmp1[i] = A[i];
	for(int i=m+1;i<len;i++) tmp1[i] = tmp3[i] = 0;
	if( n & 1 ) {
		tmp2[1] = 1, tmp2[0] = (MOD + n - 1);
		for(int i=2;i<len;i++) tmp2[i] = 0;
	}
	else {
		tmp2[0] = 1;
		for(int i=1;i<len;i++) tmp2[i] = 0;
	}
	ntt(tmp1, len, 1), ntt(tmp2, len, 1), ntt(tmp3, len, 1);
	for(int i=0;i<len;i++) tmp1[i] = 1LL*tmp1[i]*tmp2[i]%MOD*tmp3[i]%MOD;
	ntt(tmp1, len, -1);
	for(int i=0;i<=n;i++) A[i] = tmp1[i];
}
int f[MAXN + 5];
int main() {
	int n, a, b; init();
	scanf("%d%d%d", &n, &a, &b);
	if( a + b > n + 1 || a == 0 || b == 0 ) {
		printf("%d\n", 0);
		return 0;
	}
	sterling1(f, n - 1);
/*
	for(int i=0;i<=n-1;i++)
		printf("%d ", f[i]);
	puts("");
*/
	printf("%lld\n", 1LL*f[a + b - 2]*comb(a + b - 2, a - 1)%MOD);
}
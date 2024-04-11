#include<cstdio>
#include<algorithm>
using namespace std;
const int G = 3;
const int MOD = 998244353;
const int MAXN = 200000*9*2;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
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
int f[MAXN + 5];
int main() {
	int n, k, d, mx = 0;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=k;i++) {
		scanf("%d", &d);
		mx = max(mx, d);
		f[d] = 1;
	}
	int len; for(len = 1;len <= ((n>>1)*mx);len<<=1);
	ntt(f, len, 1);
	for(int i=0;i<len;i++)
		f[i] = pow_mod(f[i], (n>>1));
	ntt(f, len, -1);
	int ans = 0;
	for(int i=0;i<len;i++)
		ans = (ans + 1LL*f[i]*f[i]%MOD)%MOD;
	printf("%d\n", ans);
}
#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAXN = 800000;

namespace poly{
	int w[20], iw[20], inv[MAXN + 5];
	int pow_mod(int b, int p) {
		int ret = 1;
		while( p ) {
			if( p & 1 ) ret = 1LL*ret*b%MOD;
			b = 1LL*b*b%MOD;
			p >>= 1;
		}
		return ret;
	}
	void init() {
		inv[1] = 1;
		for(int i=2;i<=MAXN;i++)
			inv[i] = (MOD - 1LL*inv[MOD%i]*(MOD/i)%MOD)%MOD;
		for(int i=0;i<20;i++) {
			w[i] = pow_mod(3, (MOD - 1)/(1 << i));
			iw[i] = pow_mod(w[i], MOD - 2);
		}
	}
	void ntt(int *A, int n, int type) {
		for(int i=0,j=0;i<n;i++) {
			if( i < j ) swap(A[i], A[j]);
			for(int k=(n>>1);(j^=k)<k;k>>=1);
		}
		for(int i=1;(1<<i)<=n;i++) {
			int s = (1 << i), t = (s >> 1);
			int u = (type == 1 ? w[i] : iw[i]);
			for(int j=0;j<n;j+=s) {
				for(int k=0,p=1;k<t;k++,p=1LL*p*u%MOD) {
					int x = A[j+k], y = A[j+k+t];
					A[j+k] = (x + 1LL*y*p%MOD)%MOD;
					A[j+k+t] = (x + MOD - 1LL*y*p%MOD)%MOD;
				}
			}
		}
		if( type == -1 ) {
			int iv = inv[n];
			for(int i=0;i<n;i++)
				A[i] = 1LL*A[i]*iv%MOD;
		}
	}
	int length(int n) {
		int len; for(len = 1; len < n; len <<= 1);
		return len;
	}
	int t1[MAXN + 5], t2[MAXN + 5];
	void copy(int *A, int *B, int nB, int len) {
		for(int i=0;i<nB;i++) A[i] = B[i];
		for(int i=nB;i<len;i++) A[i] = 0;
	}
	void pmul(int *A, int nA, int *B, int nB, int *C) {
		int len = length(nA + nB - 1);
		copy(t1, A, nA, len);
		copy(t2, B, nB, len);
		ntt(t1, len, 1), ntt(t2, len, 1);
		for(int i=0;i<len;i++)
			C[i] = 1LL*t1[i]*t2[i]%MOD;
		ntt(C, len, -1);
	}
	int t3[MAXN + 5], t4[MAXN + 5];
	void pinv(int *A, int *B, int n) {
		if( n == 1 ) {
			B[0] = pow_mod(A[0], MOD-2);
			return ;
		}
		int m = (n + 1) >> 1;
		pinv(A, B, m);
		int len = length(n << 1);
		copy(t3, A, n, len);
		copy(t4, B, m, len);
		ntt(t3, len, 1), ntt(t4, len, 1);
		for(int i=0;i<len;i++)
			B[i] = 1LL*t4[i]*(2 + MOD - 1LL*t3[i]*t4[i]%MOD)%MOD;
		ntt(B, len, -1);
	}
	int t5[MAXN + 5], t6[MAXN + 5];
	void psqrt(int *A, int *B, int n) {
		if( n == 1 ) {
			B[0] = MOD - 1;
			return ;
		}
		int m = (n + 1) >> 1;
		psqrt(A, B, m);
		int len = length(n << 1);
		copy(t5, B, m, len);
		pinv(t5, t6, n);
		copy(t5, A, n, len);
		pmul(t5, n, t6, n, t6);
		copy(t5, B, m, n);
		for(int i=0;i<n;i++)
			B[i] = 1LL*inv[2]*(t5[i] + t6[i])%MOD;
	}
}

int f[MAXN + 5], g[MAXN + 5], t1[MAXN + 5], t2[MAXN + 5], t3[MAXN + 5];
int main() {
	int n, m, c, mn = MAXN; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &c), mn = min(mn, c), g[c]++;
	m = m + mn + 1;
	poly::init();
	for(int i=1;i<m;i++)
		t3[i] = (MOD - 4LL*g[i]%MOD) % MOD;
	t3[0] = 1;
	poly::psqrt(t3, t2, m);
	for(int i=mn;i<m;i++)
		t2[i-mn] = t2[i];
	for(int i=mn;i<m;i++)
		t3[i-mn] = 2LL*g[i]%MOD;
	poly::pinv(t3, t1, m);
	poly::pmul(t1, m, t2, m, f);
	for(int i=1;i<m-mn;i++)
		printf("%d\n", f[i]);
}
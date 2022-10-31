#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<=n;i++)
#define per(i, x, n) for(int i=x;i>=n;i--)

const int MOD = 10007;
const int M = 1000;
const int N = 2*M;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int) (1LL * x * y % MOD);}
int mpow(int b, int p) {
	int r; for(r=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

namespace linear_seq{

int t1[N + 5], t2[N + 5];
void pmul_mod(int *A, int *B, int *C, int *M, int n) {
	rep(i, 0, n - 1) t1[i] = A[i], t2[i] = B[i];
	per(i, 2*(n - 1), 0) C[i] = 0;
	rep(i, 0, n - 1) if( t1[i] )
		rep(j, 0, n - 1) C[i + j] = add(C[i + j], mul(t1[i], t2[j]));
	per(i, 2*(n - 1), n) if( C[i] )
		per(j, n, 0) C[i - j] = sub(C[i - j], mul(C[i], M[n - j]));
}

int b[N + 5], md[N + 5], bk;

void debug(int *A, int n) {
	rep(i, 1, bk) printf("%d%c", b[i], (i == bk) ? '\n' : ' ');
	rep(i, bk + 1, n) {
		int d = A[i];
		rep(j, 1, bk) d = sub(d, mul(b[j], A[i - j]));
		assert(d == 0);
	}
}

int r[N + 5], c[N + 5], ck, rk, iv, nw;
void update(int x, int d) {
	if( nw == -1 || ck - x < rk - nw ) {
		rk = ck, nw = x, iv = mpow(d, MOD - 2);
		rep(i, 1, rk) r[i] = c[i];
	}
}

int f[N + 5], g[N + 5];
int get(int *A, int n, int m) {
//	if( m <= n ) return A[m];
	
	rk = bk = 0, nw = -1;
	rep(i, 1, n) {
		int d = A[i];
		rep(j, 1, bk) d = sub(d, mul(b[j], A[i - j]));
		if( d ) {
			rep(j, 1, bk) c[j] = b[j]; ck = bk;
			if( nw == -1 ) {
				bk = i; rep(j, 1, bk) b[j] = 0; 
			} else {
				int t = i - nw + rk;
				rep(j, bk + 1, t) b[j] = 0;
				bk = max(bk, t);
				
				int coef = mul(d, iv), p = i - nw;
				b[p] = add(b[p], coef);
				rep(j, 1, rk) b[p + j] = sub(b[p + j], mul(coef, r[j]));
			}
			update(i, d);
		}
	}
	
//	debug(A, n);
	
	rep(i, 1, bk) md[bk - i] = sub(0, b[i]); md[bk] = 1;
	f[1] = 1, g[0] = 1;
	for(;m;m>>=1,pmul_mod(f, f, f, md, bk))
		if( m & 1 ) pmul_mod(g, f, g, md, bk);
	
	int ret = 0;
	rep(i, 0, bk - 1) ret = add(ret, mul(g[i], A[i + 1]));
	return ret;
}

}

int f[2][M + 5][M + 5], a[M + 5];
char s[M + 5]; int n, len;
int main() {
	scanf("%s%d", s + 1, &n), len = strlen(s + 1), n += len;
	
	int res = 0; f[0][1][len] = 1;
	rep(i, 1, M) {
		rep(j, 1, len) rep(k, j, len)
			f[1][j][k] = f[0][j][k], f[0][j][k] = 0;
		res = mul(res, 26);
		rep(j, 1, len) {
			res = add(res, f[1][j][j]);
			f[0][j][j] = add(f[0][j][j], mul(f[1][j][j], 25));
			rep(k, j + 1, len) {
				if( s[j] == s[k] ) {
					f[0][j][k] = add(f[0][j][k], mul(25, f[1][j][k]));
					if( j + 1 == k ) res = add(res, f[1][j][k]);
					else f[0][j + 1][k - 1] = add(f[0][j + 1][k - 1], f[1][j][k]);
				} else {
					f[0][j][k] = add(f[0][j][k], mul(24, f[1][j][k]));
					f[0][j + 1][k] = add(f[0][j + 1][k], f[1][j][k]);
					f[0][j][k - 1] = add(f[0][j][k - 1], f[1][j][k]);
				}
			}
		}
		
		if( n & 1 ) {
			a[i] = mul(res, 26);
			rep(p, 1, len) a[i] = add(a[i], f[0][p][p]);
		} else a[i] = res;
	}
	
	printf("%d\n", linear_seq::get(a, M, n / 2 - 1));
}
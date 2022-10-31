#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<=n;i++)

const int MOD = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int)(1LL * x * y % MOD);}
int mpow(int b, int p) {
	int r; for(r=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int h[55][55][55], fct[55];
void init(int n) {
	h[0][0][0] = fct[0] = 1;
	rep(i, 0, n) rep(j, 0, n - i) rep(k, 1, i + j) rep(p, 0, i) {
		if( p && p - 1 <= j ) h[i][j][k] = add(h[i][j][k], h[i - p][j - (p - 1)][k - 1]);
		if( p && p <= j ) h[i][j][k] = add(h[i][j][k], mul(h[i - p][j - p][k - 1], 2));
		if( p + 1 <= j ) h[i][j][k] = add(h[i][j][k], h[i - p][j - (p + 1)][k - 1]);
	}
	rep(i, 1, n) fct[i] = mul(fct[i - 1], i);
}

int f[55][55][2505], p[55][2505], t[55], g[55];
int main() {
	int n, T; scanf("%d%d", &n, &T), init(n);
	rep(i, 1, n) scanf("%d%d", &t[i], &g[i]);
	
	int c = 0, s = 0; p[0][0] = 1;
	rep(o, 1, 3) {
		rep(i, 0, c) rep(k, 0, s) f[i][0][k] = p[i][k], p[i][k] = 0;
		
		int b = 0;
		rep(x, 1, n) if( g[x] == o ) {
			rep(i, 0, c) for(int j=b;j>=0;j--) rep(k, 0, min(s, T - t[x]))
				if( f[i][j][k] ) f[i][j + 1][k + t[x]] = add(f[i][j + 1][k + t[x]], f[i][j][k]);
			b++, s += t[x];
		}
		
		rep(i, 0, c) rep(j, 0, b) rep(k, 0, s) f[i][j][k] = mul(f[i][j][k], fct[j]);
		rep(i, 0, c) rep(j, 0, b) rep(k, 0, s) if( f[i][j][k] ) {
			rep(l, 0, i + j)
				p[l][k] = add(p[l][k], mul(f[i][j][k], h[i][j][l]));
			f[i][j][k] = 0;
		}
		
		c += b;
	}
	printf("%d\n", p[1][T]);
}
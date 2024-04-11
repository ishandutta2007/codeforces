#include <bits/stdc++.h>

const int N = 4000000;
const int P = 998244353;
inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int fct[N + 5], ifct[N + 5], iv[N + 5];
int comb(int n, int m) {return mul(fct[n], mul(ifct[m], ifct[n - m]));}
void init() {
	iv[1] = 1; for(int i=2;i<=N;i++) iv[i] = sub(0, mul(P / i, iv[P % i]));
	fct[0] = 1; for(int i=1;i<=N;i++) fct[i] = mul(fct[i - 1], i);
	ifct[N] = mpow(fct[N], P - 2); for(int i=N-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
}
int main() {
	int n, m; scanf("%d%d", &n, &m), init();
	
	int e = 0;
	for(int i=0;i<=n;i++)
		e = add(e, mul(mul(fct[n], ifct[n - i]), mul(ifct[n + m], fct[n + m - i])));
	
	int ans = 0, tmp = 0;
	for(int i=1;i<=n;i++) {
		ans = add(mul(mul(fct[i], ifct[m + i]), mul(m, tmp)), e);
		ans = mul(ans, mul(m + i, iv[i]));
		tmp = add(tmp, mul(ans, mul(fct[m + i - 1], ifct[i])));
	}
	printf("%d\n", ans);
}
#include <bits/stdc++.h>

typedef long long ll;

const int P = int(1E9) + 7;
const int S = ((1 << 15) - 1);

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; b = mul(b, b), p >>= 1)
		if( p & 1 ) r = mul(r, b);
	return r;
}

int solve(ll x) {
	x /= 2, x++;
	if( !(x & 1) ) {
		int y = x / 2 % P;
		return mul(y, y + 1);
	} else {
		int y = (x + 1) / 2 % P;
		return mul(y, y);
	}
}

int main() {
	int T; ll x; scanf("%d", &T);
	while( T-- ) scanf("%lld", &x), printf("%d\n", solve(x));
}
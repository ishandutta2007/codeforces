#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int)(1LL * x * y % MOD);}
int mpow(int b, int p) {
	int r; for(r=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int main() {
	int n; scanf("%d", &n);
	
	int ans = 0;
	for(int i=0,c=1;i<=n;i++) {
		int del = 0;
		if( i == 0 ) del = mpow(sub(mpow(3, n), 3), n);
		else {
			del = mul(sub(mpow(3, i), 3), mpow(3, 1LL*n*(n-i)%(MOD-1)));
			del = add(del, mul(3, mpow(sub(mpow(3, n - i), 1), n)));
		}
		
		if( i & 1 ) ans = sub(ans, mul(c, del));
		else ans = add(ans, mul(c, del));
		
		c = mul(c, mul(n - i, mpow(i + 1, MOD - 2)));
	}
	printf("%d", sub(mpow(3, 1LL*n*n%(MOD-1)), ans));
}
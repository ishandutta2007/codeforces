#include <bits/stdc++.h>

const int N = 150000;
const int P = 998244353;
inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

int fct[2*N + 5], ifct[2*N + 5];
int c(int n, int m) {return mul(fct[n], mul(ifct[m], ifct[n-m]));}
void init() {
	fct[0] = 1; for(int i=1;i<=2*N;i++) fct[i] = mul(fct[i - 1], i);
	ifct[2*N] = mpow(fct[2*N], P - 2);
	for(int i=2*N-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
}

int a[N + 5], n;

int main() {
	scanf("%d", &n), init();
	for(int i=1;i<=(n<<1);i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + (n<<1) + 1);
	
	int ans = 0;
	for(int i=1;i<=(n<<1);i++)
		ans = (i <= n ? sub(ans, a[i] % P) : add(ans, a[i] % P));	
	printf("%d\n", mul(ans, c(n << 1, n)));
}
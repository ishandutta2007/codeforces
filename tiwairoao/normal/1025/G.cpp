#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 500;
const int P = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1LL * x * y % P);}
int mpow(int b, int p) {
	int r; for(r = 1; p; p >>= 1, b = mul(b, b))
		if( p & 1 ) r = mul(r, b);
	return r;
}


int c[N + 5], a[N + 5], n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if( a[i] != -1 ) c[a[i]]++;
	}
	int phi0 = 0;
	for(int i=1;i<=n;i++)
		phi0 = add(phi0, sub(1, mpow(2, c[i])));
	int phiT = sub(1, mpow(2, n - 1));
	printf("%d\n", sub(phi0, phiT));
}
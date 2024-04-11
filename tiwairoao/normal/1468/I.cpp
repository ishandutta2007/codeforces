#include <bits/stdc++.h>

int n, dx1, dy1, dx2, dy2;

int gcd(int x, int y) {return (y == 0) ? x : gcd(y, x % y);}
long long mabs(long long x) {
	return (x >= 0 ? x : -x);
}
int main() {
	scanf("%d%d%d%d%d", &n, &dx1, &dy1, &dx2, &dy2);
	if( 1ll * dx1 * dy2 - 1ll * dx2 * dy1 == 0 ) {
		puts("NO"); return 0;
	}
	
	int dx = gcd(dx1, dx2), x1 = dx1 / dx, x2 = dx2 / dx;
	int dy = gcd(dy1, dy2), y1 = dy1 / dy, y2 = dy2 / dy;
	long long x = mabs(1ll * dx2 * y1 - 1ll * dx1 * y2);
	long long y = mabs(gcd(dy1, dy2));
	
	if( x > n || y > n || x * y != n ) {
		puts("NO");
	} else {
		puts("YES");
		for(int i=0;i<x;i++) for(int j=0;j<y;j++)
			printf("%d %d\n", i, j);
	}
}
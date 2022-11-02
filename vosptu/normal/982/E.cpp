#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void ext_gcd(int a,int b,long long &x,long long &y, int c) {
	if(b==0){x=c,y=0;return;}
	ext_gcd(b,a%b,y,x,c),y-=a/b*x;
}

int gcd(int a, int b) {
	if (!a)
		return b;
	else
		return gcd(b % a, a);
}

int main() {
	int n, m, x, y, vx, vy;
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &vx, &vy);
	if (vx == 0) {
		if (vy > 0) {
			if (x == 0) {
				printf("%d %d\n", 0, m);
			}else if (x == n) {
				printf("%d %d\n", n, m);
			}else {
				printf("-1\n");
			}
		}
		if (vy < 0) {
			if (x == 0) {
				printf("%d %d\n", 0, 0);
			}else if (x == n) {
				printf("%d %d\n", n, 0);
			}else {
				printf("-1\n");
			}
		}
		return 0;
	}
	if (vy == 0) {
		if (vx > 0) {
			if (y == 0) {
				printf("%d %d\n", n, 0);
			}else if (y == m) {
				printf("%d %d\n", n, m);
			}else {
				printf("-1\n");
			}
		}
		if (vx < 0) {
			if (y == 0) {
				printf("%d %d\n", 0, 0);
			}else if (y == m) {
				printf("%d %d\n", 0, m);
			}else {
				printf("-1\n");
			}
		}
		return 0;
	}

	int k1, k2;
	if (vx == 1) {
		k1 = (n - x) % n;
	}else {
		k1 = x % n;
	}

	if (vy == 1) {
		k2 = (m - y) % m;
	}else {
		k2 = y % m;
	}

	int g = gcd(n, m);
	if ((k1 - k2) % g != 0) {
		printf("-1\n");
		return 0;
	}

	long long xx, yy;
	ext_gcd(n, m, xx, yy, (k2 - k1) / g);
	// printf("%I64d\n", xx);
	xx %= (m / g);
	long long S = xx * n + k1;
	long long lcm = 1LL * n * m / g;
	S = (S % lcm + lcm) % lcm;
	xx = x + S * vx;
	yy = y + S * vy;

	printf("%I64d %I64d\n", (xx % (2 * n) + 2 * n) % (2 * n), (yy % (2 * m) + 2 * m) % (2 * m));
	
}
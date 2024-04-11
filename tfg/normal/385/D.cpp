#include <iostream>
#include <cmath>
#include <iomanip>

typedef double ld;

const ld PI = acos(-1);

struct PT {
	ld x, y;
	PT(ld x = 0, ld y = 0) {
		this->x = x;
		this->y = y;
	}

	PT rotate(ld angle) {
		return PT(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
	}

	double operator * (PT o) {
		return x * o.x + y * o.y;
	}

	double operator % (PT o) {
		return x * o.y - y * o.x;
	}

	PT operator * (ld c) {
		return PT(x * c, y * c);
	}

	PT operator - (PT o) {
		return PT(x - o.x, y - o.y);
	}
};

PT pts[20];
ld a[20];
ld dp[1 << 20];

int main() {
	int n, l, r;
	std::cin >> n >> l >> r;
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y >> a[i];
	}
	for(int i = 0; i < (1 << n); i++) {
		dp[i] = l;
		for(int j = 0; j < n; j++) {
			if((1 << j) & i) {
				int mask = (1 << j) ^ i;
				PT dir = PT(dp[mask], 0) - pts[j];
				dir = dir.rotate(a[j] / 180.0 * PI);
				PT base = PT(r, 0) - pts[j];
				if(base % dir >= -1e-9) {
					std::cout << r - l << std::endl;
					return 0;
				}
				dp[i] = std::max(dp[i], pts[j].x - dir.x / dir.y * pts[j].y);
			}
		}
	}
	std::cout << std::fixed << std::setprecision(20) << dp[(1 << n) - 1] - l << '\n';
}
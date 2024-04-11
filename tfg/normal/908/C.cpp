#include <iostream>
#include <iomanip>

typedef long double ld;

ld y[1010];
int a[1010];

int main() {
	int n, rr;
	std::cin >> n >> rr;
	std::cout << std::fixed << std::setprecision(10);
	for(int i = 0; i < n; i++) {
		ld ans = rr;
		std::cin >> a[i];
		bool flag = false;
		for(int j = 0; j < i; j++) {
			if(std::max(a[i] - a[j], a[j] - a[i]) <= 2 * rr) {
				//std::cout << "(" << i << ", " << j << ")\n";
				ld l = y[j], r = 1e10;
				ld dx = std::max(a[i] - a[j], a[j] - a[i]);
				for(int k = 0; k < 100; k++) {
					ld mid = (l + r) / 2;
					ld dy = mid - y[j];
					//std::cout << double(mid) << ": " << double(dy * dy + dx * dx - 4 * rr * rr) << "\n";
					//std::cout << r << '\n';
					if(dy * dy + dx * dx - 4 * rr * rr > 0) {
						r = mid;
					} else {
						l = mid;
					}
				}
				ans = std::max(ans, l);
				//std::cout << (double)l << "\n";
			}
		}
		y[i] = ans;
		std::cout << (double) ans << (i + 1 == n ? '\n' : ' ');
	}
}
#include <iostream>

const int ms = 100100;

int d[ms], h[ms];

int peak(int down, int up, int tim) {
	tim -= up - down;
	down = up;
	return up + tim / 2;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		std::cin >> d[i] >> h[i];
	}
	h[0] = d[1] + h[1] - 1;
	d[0] = 1;
	h[m + 1] = h[m] + n - d[m];
	int ans = std::max(h[0], h[m + 1]);
	for(int i = 1; i <= m; i++) {
		if(std::max(h[i] - h[i - 1], h[i - 1] - h[i]) > d[i] - d[i - 1]) {
			std::cout << "IMPOSSIBLE\n";
			return 0;
		}
		ans = std::max(ans, peak(std::min(h[i], h[i - 1]), std::max(h[i], h[i - 1]), d[i] - d[i - 1]));
	}
	std::cout << ans << '\n';
}
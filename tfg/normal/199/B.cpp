#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x[2], y[2], r[2], R[2];
	for(int i = 0; i < 2; i++) {
		std::cin >> x[i] >> y[i] >> r[i] >> R[i];
	}
	int dx = x[0] - x[1], dy = y[0] - y[1];
	int dist = dx * dx + dy * dy;
	int ans = 0;
	if(R[0] > R[1]) {
		std::swap(r[0], r[1]);
		std::swap(R[0], R[1]);
	}
	// dist + R[0] <= r[1]
	// dist >= R[1] + R[0]
	// now I know there's no way to get outer for the first
	if(dist <= (R[0] - r[1]) * (R[0] - r[1]) && R[0] <= r[1]) {
		ans = 4;
	} else if(dist >= (R[0] + R[1]) * (R[0] + R[1])) {
		ans = 4;
	} else {
		ans = 2;
		// dist - r[0] < R[1] && dist + r[0] > r[1]
		if(dist < (r[1] + R[0]) * (r[1] + R[0]) &&
		   (dist > (r[1] - r[0]) * (r[1] - r[0]) || r[1] < r[0])) {
			ans--;
		}
		std::swap(r[0], r[1]);
		std::swap(R[0], R[1]);
		if(dist < (r[1] + R[0]) * (r[1] + R[0]) &&
		   (dist > (r[1] - r[0]) * (r[1] - r[0]) || r[1] < r[0])) {
			ans--;
		}
		std::swap(r[0], r[1]);
		std::swap(R[0], R[1]);
		// R[0] <= - (dist - R[1])
		// dist < R[1] - R[0]
		if(dist <= (R[1] - R[0]) * (R[1] - R[0])) {
			ans++;
		}
	}
	std::cout << ans << std::endl;
}
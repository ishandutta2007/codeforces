#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool between(int l, int x, int r) {
	if(l > r) {
		std::swap(l, r);
	}
	return l <= x && x <= r;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	int qx, qy;
	int kx, ky;
	int wx, wy;
	std::cin >> n;
	std::cin >> qx >> qy;
	std::cin >> kx >> ky;
	std::cin >> wx >> wy;
	bool valid = !between(wx, qx, kx) && !between(wy, qy, ky);
	std::cout << (valid ? "YES\n" : "NO\n");
}
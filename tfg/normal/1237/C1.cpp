#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
	int x, y, z, id;
	void read() {
		std::cin >> x >> y >> z;
	}
	int dist(PT o) const {
		return abs(x - o.x) + abs(y - o.y) + abs(z - o.z);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> pts(n);
	for(int i = 0; i < n; i++) {
		pts[i].read();
		pts[i].id = i;
	}
	while(n != 0) {
		int ans = 1;
		for(int i = 2; i < n; i++) {
			if(pts[i].dist(pts[0]) < pts[ans].dist(pts[0])) {
				ans = i;
			}
		}
		std::cout << pts[0].id + 1 << ' ' << pts[ans].id + 1 << '\n';
		std::swap(pts[ans], pts.back());
		pts.pop_back();
		std::swap(pts.back(), pts[0]);
		pts.pop_back();
		n -= 2;
	}
}
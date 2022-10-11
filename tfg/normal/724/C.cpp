#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::map<int, std::vector<int>> diag[2];
	std::vector<int> x(k), y(k);
	for(int i = 0; i < k; i++) {
		std::cin >> x[i] >> y[i];
		diag[0][x[i]+y[i]].push_back(i);
		diag[1][x[i]-y[i]].push_back(i);
	}
	const long long INF = 1e18;
	std::vector<long long> ans(k, INF);
	int dx = 1, dy = 1;
	int xx = 0, yy = 0;
	long long cur = 0;
	for(int rep = 0; rep < 1000000; rep++) {
		int distX = dx == 1 ? n - xx : xx;
		int distY = dy == 1 ? m - yy : yy;
		// solve events
		if(dx * dy == 1) {
			auto it = diag[1].find(xx-yy);
			if(it != diag[1].end()) {
				for(auto val : it->second) {
					ans[val] = std::min(ans[val], cur + abs(x[val] - xx));
				}
				diag[1].erase(it);
			}
		} else {
			auto it = diag[0].find(xx+yy);
			if(it != diag[0].end()) {
				for(auto val : it->second) {
					ans[val] = std::min(ans[val], cur + abs(x[val] - xx));
				}
				diag[0].erase(it);
			}
		}
		int dist = std::min(distX, distY);
		cur += dist;
		xx += dist * dx;
		yy += dist * dy;
		if(distX == distY) {
			break;
		}
		if(distX < distY) {
			dx = -dx;
		} else {
			dy = -dy;
		}
	}
	for(auto val : ans) {
		if(val == INF) {
			val = -1;
		}
		std::cout << val << '\n';
	}
}
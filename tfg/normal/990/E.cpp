#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<bool> blocked(n, false);
	for(int i = 0; i < m; i++) {
		int pos;
		std::cin >> pos;
		blocked[pos] = true;
	}
	std::vector<int> left(n, 0);
	if(blocked[0]) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 1; i < n; i++) {
		if(blocked[i]) {
			left[i] = left[i - 1];
		} else {
			left[i] = i;
		}
	}
	long long cost = 1e18;
	for(int i = 1; i <= k; i++) {
		long long curCost;
		std::cin >> curCost;
		int steps = 0;
		for(int j = 0; j < n; j = left[j] + i, steps++) {
			if(left[j] + i <= j) {
				steps = -1;
				break;
			}
		}
		if(steps != -1) {
			cost = std::min(cost, steps * curCost);
		}
	}
	if(cost >= 1e17) {
		cost = -1;
	}
	std::cout << cost << std::endl;
}
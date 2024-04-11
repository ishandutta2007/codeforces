#define NDEBUG

#include <iostream>
#include <vector>

int const N = 31;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, l; std::cin >> n >> l;
	std::vector<uint64_t> cost (N, 2e18);
	for (int i = 0; i < n; ++i) 
		std::cin >> cost[i];
	
	while (true) {
		bool doneat = false;
		for (int i = 1; i < N; ++i) {
			if (cost[i-1] > cost[i]) {
				cost[i-1] = cost[i];
				doneat = true;
			}
			if (cost[i] > 2*cost[i-1]) {
				cost[i] = 2*cost[i-1];
				doneat = true;
			}
		}
		if (!doneat) break;
	}
	
	std::vector<int> parts;
	uint64_t normal_cost = 0;
	for (int i = N; i --> 0;) {
		int64_t k = 1ULL << i;
		if (l >= k) {
			l -= k;
			parts.push_back(i);
			normal_cost += cost[i];
		}
	}
	
	uint64_t prefixsum = 0;
	for (size_t i = 0; i < parts.size(); ++i) {
		// consider replacing [i..parts.size() ) with parts[i]+1
		normal_cost = std::min(normal_cost, prefixsum + cost[parts[i]+1]);
		// it's guaranteed that parts[i] < 30 (because 2^30 > max L),
		// so parts[i]+1 < 31 == N
		
		prefixsum += cost[parts[i]];
	}
	
	std::cout << normal_cost << '\n'; // not so normal anymore
}
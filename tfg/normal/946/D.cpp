#include <iostream>
#include <vector>

long long best[501];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	while(n--) {
		std::vector<int> pos;
		std::string str;
		std::cin >> str;
		for(int i = 0; i < m; i++) {
			if(str[i] == '1') {
				pos.push_back(i);
			}
		}
		std::vector<int> cost(pos.size() + 1, 1e9);
		cost.back() = 0;
		for(int i = 0; i < pos.size(); i++) {
			for(int j = i; j < pos.size(); j++) {
				cost[pos.size() - (j - i + 1)] = std::min(cost[pos.size() - (j - i + 1)], pos[j] - pos[i] + 1);
			}
		}
		for(int i = k; i >= 0; i--) {
			best[i] = best[i] + cost[0];
			for(int j = 0; j < std::min(i + 1, (int)cost.size()); j++) {
				best[i] = std::min(best[i], best[i - j] + cost[j]);
			}
		}
	}
	std::cout << best[k] << '\n';
}
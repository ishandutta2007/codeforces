#include <iostream>

int main() {
	int one, fone, all_one, ans;
	std::cin >> one >> fone >> all_one >> ans;
	int cost[2] = {0, 0};
	int freq[2];
	std::cin >> freq[0] >> freq[1];
	for(int k = 0; k < 2; k++) {
		while(freq[k]--) {
			int hmm;
			std::cin >> hmm;
			cost[k] += std::min(hmm * one, fone);
		}
		cost[k] = std::min(all_one, cost[k]);
	}
	std::cout << std::min(cost[0] + cost[1], ans) << std::endl;
}
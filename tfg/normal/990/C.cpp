#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const int ms = 1e6 + 2;
	std::vector<int> freq(ms, 0);
	long long pairs = 0;
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		int curBal = 0;
		int minBal = 0;
		int maxBal = 0;
		for(auto c : str) {
			curBal += c == '(' ? 1 : -1;
			minBal = std::min(minBal, curBal);
			maxBal = std::min(maxBal, curBal);
		}
		if(curBal == 0) {
			if(minBal == 0) {
				pairs += 2 * freq[ms / 2]++ + 1;
			}
			continue;
		} else if(curBal > 0) {
			// first part
			if(minBal != 0) {
				continue;
			}
			pairs += freq[ms / 2 - curBal];
			freq[ms / 2 + curBal]++;
		} else {
			// second part
			if(minBal != curBal) {
				continue;
			}
			pairs += freq[ms / 2 - curBal];
			freq[ms / 2 + curBal]++;
		}
	}
	std::cout << pairs << std::endl;
}
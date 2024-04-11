#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector<int> freq(26, 0);
	for(auto a : str) {
		freq[a - 'a']++;
	}
	std::sort(freq.begin(), freq.end());
	bool ans = (freq[25] > 1 || freq[24] == 0);
	std::cout << (ans ? "Yes\n" : "No\n");
}
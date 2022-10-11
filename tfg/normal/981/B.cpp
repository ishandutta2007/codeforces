#include <iostream>
#include <map>
#include <cstdio>

int main() {
	std::map<int, int> freq;
	for(int k = 0; k < 2; k++) {
		int n;
		std::cin >> n;
		while(n--) {
			int a, b;
			scanf("%d %d", &a, &b);
			freq[a] = std::max(freq[a], b);
		}
	}
	long long ans = 0;
	for(auto a : freq) {
		ans += a.second;
	}
	std::cout << ans << std::endl;
}
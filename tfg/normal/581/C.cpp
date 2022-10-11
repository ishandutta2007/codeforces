#include <iostream>

int freq[10];

int main() {
	int n, k;
	std::cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		ans += v / 10;
		freq[(10 - v % 10) % 10]++;
	}
	for(int i = 1; i < 10; i++) {
		int use = std::min(k / i, freq[i]);
		k -= use * i;
		ans += use;
	}
	ans += k / 10;
	ans = std::min(ans, n * 10);
	std::cout << ans << std::endl;
}
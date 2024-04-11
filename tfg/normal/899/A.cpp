#include <iostream>

int f[3];

int main() {
	int n;
	std::cin >> n;
	while(n--) {
		int t;
		std::cin >> t;
		f[t]++;
	}
	int ans = std::min(f[1], f[2]);
	f[1] -= ans;
	ans += f[1] / 3;
	std::cout << ans << '\n';
}
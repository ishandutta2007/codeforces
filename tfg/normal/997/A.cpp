#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, x, y;
	std::cin >> n >> x >> y;
	int groups = 0;
	std::string str;
	std::cin >> str;
	for(int i = 0; i < n; i++) {
		if(str[i] == '0' && (i == 0 || str[i - 1] == '1')) {
			groups++;
		}
	}
	if(groups == 0) {
		std::cout << "0\n";
		return 0;
	}
	long long ans = 1e18;
	for(int i = 1; i <= groups; i++) {
		ans = std::min(ans, (long long) i * y + (long long) (groups - i) * x);
	}
	std::cout << ans << std::endl;
}
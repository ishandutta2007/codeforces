#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, k;
	std::cin >> n >> k;
	if(n + n - 1 < k || k == 1) {
		std::cout << "0\n";
		return 0;
	}
	long long mn = (k + 2) / 2;
	long long ans = std::min((k - 1) / 2, n - mn + 1);
	ans = std::max(ans, 0LL);
	std::cout << ans << std::endl;
}
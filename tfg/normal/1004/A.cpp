#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int ans = 2;
	int n;
	long long k;
	std::cin >> n >> k;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i + 1 < n; i++) {
		if(a[i + 1] - a[i] == 2 * k) {
			ans++;
		} else if(a[i + 1] - a[i] > 2 * k) {
			ans += 2;
		}
	}
	std::cout << ans << std::endl;
}
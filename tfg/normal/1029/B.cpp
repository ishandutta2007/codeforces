#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int cur = 1, ans = 1;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i) {
			if(2 * a[i-1] >= a[i]) {
				cur++;
			} else {
				cur = 1;
			}
			ans = std::max(ans, cur);
		}
	}
	std::cout << ans << std::endl;
}
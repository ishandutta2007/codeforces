#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int to = 1;
	int ans = 1;
	while(to < n) {
		int use = to + 1;
		if((long long)use + to > n) {
			to = n;
		} else {
			to += use;
		}
		ans++;
	}
	std::cout << ans << std::endl;
}
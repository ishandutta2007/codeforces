#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int police = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] < 0) {
			if(police) {
				police--;
			} else {
				ans++;
			}
		} else {
			police += a[i];
		}
	}
	std::cout << ans << std::endl;
}
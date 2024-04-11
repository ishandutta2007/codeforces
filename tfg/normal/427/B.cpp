#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n, t, c;
	std::cin >> n >> t >> c;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] = (a[i] <= t ? 1 : 0);
	}
	int ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) r++;
		if(r - l >= c && a[l] == 1) {
			ans += r - l - c + 1;
		}
	}
	std::cout << ans << std::endl;
}
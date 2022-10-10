#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::string ans;
		std::vector<std::pair<int, int>> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i].first >> a[i].second;
		}
		std::sort(a.begin(), a.end(), [](std::pair<int, int> a1, std::pair<int, int> a2) { return a1.first + a1.second < a2.first + a2.second; });
		bool valid = true;
		int x = 0, y = 0;
		for(int i = 0; i < n; i++) {
			int toX = a[i].first, toY = a[i].second;
			valid = valid && toX >= x && toY >= y;
			while(x < toX) {
				ans += "R";
				x++;
			}
			while(y < toY) {
				ans += "U";
				y++;
			}
		}
		if(valid) {
			std::cout << "YES\n";
			std::cout << ans << '\n';
		} else {
			std::cout << "NO\n";
		}
	}
}
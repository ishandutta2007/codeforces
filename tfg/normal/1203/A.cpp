#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		bool valid = true;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			a[i]--;
		}
		for(int i = 0; i < n; i++) {
			int x = (a[i]+1)%n, y = (a[i]-1+n)%n;
			int cnt = 0;
			for(int j = -1; j <= 1; j += 2) {
				if(x == a[(i+j+n)%n] || y == a[(i+j+n)%n]) {
					cnt++;
				}
			}
			if(cnt < 2) {
				valid = false;
			}
		}
		std::cout << (valid ? "YES\n" : "NO\n");
	}
}
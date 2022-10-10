#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		a[x] = i;
	}
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		b[x] = i;
		p[n-b[x]-1] = a[x];
	}
	int ans = 0;
	int mn = n;
	for(int i = 0; i < n; i++) {
		int x = p[i];
		if(mn < x) {
			ans++;
		} else {
			mn = x;
		}
	}
	std::cout << ans << '\n';
}
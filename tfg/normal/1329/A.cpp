#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m, n;
	std::cin >> m >> n;
	long long sum = 0;
	std::vector<int> a(n);
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	int on = 0;
	for(int i = n-1; i >= 0; i--) {
		sum -= a[i];
		if(a[i] > on && sum >= m - a[i]) {
			b[i] = 1;
			on = a[i];
		} else if(a[i] > on) {
			// sum < m - a[i]
			// a[i] < m - sum
			// this means that shit's wrong
			std::cout << "-1\n";
			return 0;
		} else {
			int need = (int) std::max(1LL, m - on - sum);
			need = std::min(need, a[i]);
			b[i] = on + 1 + need - a[i];
			on += need;
			//std::cout << "need is " << need << ", " << m << " - " << sum << " == " << m - sum << '\n';
			if(on > m) {
				std::cout << "-1\n";
				return 0;
			}
		}
		//std::cout << "at " << i + 1 << " got " << b[i] << " on at " << on << '\n';
	}
	if(on != m) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}
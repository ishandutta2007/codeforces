#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<bool> b(n, false);
	int cnt = 0;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] % 2 == 0) {
			a[i] /= 2;
		} else if(a[i] >= 0) {
			b[i] = true;
			a[i] /= 2;
			cnt++;
		} else {
			b[i] = true;
			a[i] /= 2;
			a[i]--;
			cnt++;
		}
		sum += a[i];
	}
	for(int i = 0; i < n; i++) {
		if(sum < 0 && b[i]) {
			sum++;
			a[i]++;
		}
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}
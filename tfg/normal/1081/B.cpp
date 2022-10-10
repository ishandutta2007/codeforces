#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> a[ms];
int b[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		a[n - v].push_back(i);
	}
	int c = 1;
	for(int i = 1; i <= n; i++) {
		if((int) a[i].size() % i != 0) {
			std::cout << "Impossible\n";
			return 0;
		}
		for(int j = 0; j < (int) a[i].size(); j++) {
			b[a[i][j]] = c + j / i;
		}
		c += (int) a[i].size() / i;
	}
	std::cout << "Possible\n";
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}
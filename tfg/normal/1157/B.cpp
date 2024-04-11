#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string a;
	std::vector<char> to(10);
	std::cin >> n >> a;
	for(int i = 1; i < 10; i++) {
		std::cin >> to[i];
	}
	int x = 0;
	while(x < n && a[x] >= to[a[x] - '0']) {
		x++;
	}
	while(x < n && a[x] <= to[a[x] - '0']) {
		a[x] = to[a[x] - '0'];
		x++;
	}
	std::cout << a << '\n';
}
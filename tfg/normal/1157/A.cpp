#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int f(int x) {
	x++;
	while(x % 10 == 0) x /= 10;
	return x;
}

std::set<int> wtf;

int g(int x) {
	wtf.insert(x);
	return x == 1 ? 1 : 1 + g(f(x));
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= 9; i++) {
		wtf.insert(i);
	}
	g(n);
	std::cout << wtf.size() << '\n';
}
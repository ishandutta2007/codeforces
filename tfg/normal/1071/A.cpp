#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e6;

bool got[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b;
	std::cin >> a >> b;
	if(a + b == 0) {
		std::cout << "0\n\n0\n\n";
		return 0;
	}
	long long ans = 1;
	while((ans + 2) * (ans + 1) / 2 <= a + b) ans++;
	std::vector<int> f, s;
	for(int i = 1; i <= a; i++) {
		f.push_back(i);
		a -= i;
	}
	for(int i = (int) f.size() - 1; a > 0; i--) {
		a--;
		f[i]++;
	}
	for(auto v : f) {
		got[v] = true;
	}
	for(int i = 1; i <= b; i++) {
		if(!got[i]) {
			b -= i;
			s.push_back(i);
		}
	}
	assert((int) f.size() + s.size() == ans);
	std::cout << f.size() << '\n';
	for(int i = 0; i < (int) f.size(); i++) {
		if(i) std::cout << ' ';
		std::cout << f[i];
	}std::cout << '\n';
	std::cout << s.size() << '\n';
	for(int i = 0; i < (int) s.size(); i++) {
		if(i) std::cout << ' ';
		std::cout << s[i];
	}std::cout << '\n';
}
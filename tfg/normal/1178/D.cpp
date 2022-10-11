#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector< std::pair<int, int> > ans;

const int ms = 1010;

bool prime[ms];

void print(int b, int n) {
	std::vector<int> deg(n, 2);
	for(int i = 0; i < n; i++) {
		int u = b + i;
		int v = b + (i+1)%n;
		ans.emplace_back(u, v);
	}
	int got = n;
	for(int i = 0; i + 2 < n && !prime[got];) {
		got++;
		ans.emplace_back(b + i, b + i + 2);
		if(i % 4 == 0) {
			i++;
		} else if(i % 4 == 1) {
			i += 3;
		}
	}
	assert(prime[got]);
}

int main() {
	for(int i = 2; i < ms; i++) {
		prime[i] = true;
	}
	for(int i = 2; i < ms; i++) {
		if(!prime[i]) continue;
		for(int j = i + i; j < ms; j += i) {
			prime[j] = false;
		}
	}
	for(int i = 3; i <= 1000; i++) {
		break;
		print(1, i);
		ans.clear();
	}
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	print(1, n);
	std::cout << ans.size() << '\n';
	for(auto e : ans) {
		std::cout << e.first << ' ' << e.second << '\n';
	}
}
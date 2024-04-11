#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

std::vector<int> edges[ms];
int a[ms], c[ms];

void fix(int on, int sum, int shift) {
	a[on] += sum;
	a[on] += a[on] >= shift ? 1 : 0;
	for(auto to : edges[on]) {
		fix(to, sum, shift);
	}
}

int solve(int on) {
	int cnt = 0;
	for(auto to : edges[on]) {
		int size = solve(to);
		fix(to, cnt, c[on]);
		cnt += size;
	}
	if(cnt < c[on]) {
		std::cout << "NO\n";
		exit(0);
	}
	a[on] = c[on];
	return cnt + 1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int p;
		std::cin >> p >> c[i];
		edges[p].push_back(i);
	}
	solve(0);
	std::cout << "YES\n";
	for(int i = 1; i <= n; i++) {
		std::cout << a[i] << (i == n ? '\n' : ' ');
	}
}
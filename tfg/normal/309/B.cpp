#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 20;
const int ms = 1001000;

int to[me][ms], cost[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, r, c;
	std::cin >> n >> r >> c;
	std::vector<std::string> words(n);
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> words[i];
		a[i] = words[i].size();
	}
	for(int i = 0; i < n; i++) {
		to[0][i] = i;
		cost[i] = -1;
		if(i && to[0][i-1] > i) {
			to[0][i] = to[0][i-1];
			cost[i] = cost[i-1] - a[i-1] - 1;
		}
		while(to[0][i] < n && cost[i] + a[to[0][i]] + 1 <= c) {
			cost[i] += a[to[0][i]++] + 1;
		}
		if(cost[i] < 0) {
			cost[i] = 0;
		}
	}
	to[0][n] = n;
	for(int i = 1; i < me; i++) {
		for(int j = 0; j < n; j++) {
			to[i][j] = to[i-1][to[i-1][j]];
		}
		to[i][n] = n;
	}
	int st = 0, en = -1;
	for(int i = 0; i < n; i++) {
		int on = i;
		for(int j = 0; j < me; j++) {
			if((1 << j) & r) {
				on = to[j][on];
			}
		}
		if(en - st < on - i) {
			en = on;
			st = i;
		}
	}
	while(st != en) {
		int on = to[0][st];
		for(; st < on; st++) {
			std::cout << words[st] << (st + 1 == on ? '\n' : ' ');
		}
	}
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MAGIC = 1000;
const int mv = 2 * MAGIC * 8 + 10;

long long f[2][9];

void go(std::bitset<mv> &b, int x, long long v) {
	if(x > mv) return;
	if(v == 0) return;
	if(v % 2 == 0) {
		if(x > 0) {
			b |= b << x;
		} else {
			b |= b >> (-x);
		}
		v--;
	}
	go(b, x * 2, v / 2);
	if(x > 0) {
		b |= b << x;
	} else {
		b |= b >> (-x);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long w, c = 0;
	std::cin >> w;
	for(int i = 1; i <= 8; i++) {
		std::cin >> f[0][i];
		long long use = std::min((w - c) / i, f[0][i]);
		f[0][i] -= use;
		f[1][i] += use;
		c += use * i;
	}
	std::bitset<mv> can;
	can[mv / 2] = true;
	for(int i = 1; i <= 8; i++) {
		go(can, i, f[0][i]);
		go(can, -i, f[1][i]);
	}
	long long ans = c;
	for(int i = 0; i < mv; i++) {
		long long val = c + i - mv / 2;
		if(val <= w && can[i]) {
			ans = std::max(ans, val);
		}
	}
	std::cout << ans << '\n';
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int f[ms];
int go[ms];

int cnt = 0, mx = 0;

void add(int x) {
	if(x == 0) return;
	if(f[x] == 0) {
		cnt++;
	}
	f[x]++;
}

void rem(int x) {
	if(x == 0) return;
	f[x]--;
	if(f[x] == 0) {
		cnt--;
	}
}

void lul(int x) {
	rem(go[x]++);
	add(go[x]);
	mx = std::max(mx, go[x]);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans = 0;
	int good = -1;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(good == -1) {
			good = x;
		}
		if(good != x) {
			good = -2;
		}
		lul(x);
		if(good != -2 || (cnt == 1 && f[1] > 0) || (cnt == 2 && f[1] == 1) || (cnt == 2 && f[mx] == 1 && f[mx-1] > 0)) {
			ans = i + 1;
		}
	}
	std::cout << ans << '\n';
}
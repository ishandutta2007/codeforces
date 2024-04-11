#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int c = 1;
int to[300300 * 30][2];
int size[300300 * 30];

int addString(int x) {
	int on = 0;
	for(int i = 29; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if(to[on][bit] == 0) {
			to[on][bit] = c++;
		}
		on = to[on][bit];
		size[on]++;
	}
	return on;
}

int getMax(int x) {
	int on = 0;
	int ans = 0;
	for(int i = 29; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if(to[on][bit] && size[to[on][bit]]) {
			on = to[on][bit];
		} else {
			on = to[on][bit^1];
			ans |= 1 << i;
		}
		size[on]--;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		addString(x);
	}
	for(int i = 0; i < n; i++) {
		std::cout << getMax(a[i]) << (i + 1 == n ? '\n' : ' ');
	}
}
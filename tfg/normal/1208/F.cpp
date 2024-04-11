#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 21;
const int ms = 1 << me;

int ids[ms][2];

inline void push(int a[2], int x) {
	//push in order of largest
	//largest first
	if(x < a[1]) {

	} else if(x < a[0]) {
		// x >= a[1] && x < a[0]
		a[1] = x;
	} else {
		a[1] = a[0];
		a[0] = x;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	memset(ids, -1, sizeof ids);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		push(ids[a[i]], i);
	}
	for(int len = 1; len + len < ms; len += len) {
		for(int i = 0; i < ms; i += len+len) {
			for(int j = 0; j < len; j++) {
				// and
				// push to 0
				push(ids[i+j], ids[i+j+len][0]);
				push(ids[i+j], ids[i+j+len][1]);
			}
		}
	}
	int ans = 0;
	for(int b = me-1; b >= 0; b--) {
		for(int i = 0; i < n; i++) {
			int mask = (ans | (1 << b)) & (~a[i]);
			mask &= ~((1<<b)-1);
			if(ids[mask][1] > i) {
				ans |= 1 << b;
				break;
			}
		}
	}
	std::cout << ans << std::endl;
}
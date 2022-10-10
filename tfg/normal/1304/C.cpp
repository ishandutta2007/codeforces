#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	long long l, r;
	std::cin >> n >> l;
	r = l;
	long long cur = 0;
	bool good = true;
	while(n--) {
		long long t, low, up;
		std::cin >> t >> low >> up;
		//std::cout << "got (" << t << ", " << low << ", " << up << ")" << std::endl;
		l -= (t - cur);
		r += (t - cur);
		cur = t;
		l = std::max(l, low);
		r = std::min(r, up);
		if(l > r) {
			good = false;
		}
	}
	std::cout << (good ? "YES\n" : "NO\n");
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		solve();
	}
}
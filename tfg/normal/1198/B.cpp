#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int bit[ms];

int qry(int x) {
	int ans = 0;
	for(; x < ms; x += x & -x) {
		ans = std::max(ans, bit[x]);
	}
	return ans;
}

void upd(int x, int v) {
	for(; x > 0; x -= x & -x) {
		bit[x] = std::max(v, bit[x]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> last(n, 1);
	for(auto &v : a) std::cin >> v;
	int q;
	std::cin >> q;
	for(int i = 1; i <= q; i++) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int p, x;
			std::cin >> p >> x;
			p--;
			a[p] = x;
			last[p] = i;
		} else {
			int x;
			std::cin >> x;
			upd(i, x);
		}
	}
	for(int i = 0; i < n; i++) {
		a[i] = std::max(a[i], qry(last[i]));
		std::cout << a[i] << '\n';
	}
}
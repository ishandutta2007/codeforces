#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 30;

struct Gauss {
	int table[me];

	Gauss() {
		for(int i = 0; i < me; i++) {
			table[i] = 0;
		}
	}

	int size() {
		int ans = 0;
		for(int i = 0; i < me; i++) {
			if(table[i]) ans++;
		}
		return ans;
	}

	bool can(int x) {
		for(int i = me-1; i >= 0; i--) {
			x = std::min(x, x ^ table[i]);
		}
		return x == 0;
	}

	void add(int x) {
		for(int i = me-1; i >= 0; i--) {
			if(table[i] == 0 && ((1 << i) & x)) {
				table[i] = x;
				x = 0;
			} else {
				x = std::min(x, x ^ table[i]);
			}
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int x = 0;
	std::vector<int> a(n);
	Gauss hmm;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		x ^= v;
		a[i] = x;
		hmm.add(x);
		//std::cout << "after adding " << x << " got size " << hmm.size() << '\n';
	}
	if(x == 0) {
		std::cout << "-1\n";
		return 0;
	}
	std::cout << hmm.size() << '\n';
}
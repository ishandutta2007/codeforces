#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int nn) {
		this->n = nn;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	int search(int sum) {
		int wot = sum;
		int x = 0;
		for(int i = 22; i >= 0; i--) {
			int newX = x + (1 << i);
			if(newX <= n && sum > bit[newX]) {
				x = newX;
				sum -= bit[x];
			}
		}
		assert(qry(x) < wot && qry(x+1) >= wot);
		return x + 1;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	FenwickTree<int> tree;
	tree.init(n);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		tree.upd(x, 1);
	}
	for(int i = 0; i < q; i++) {
		int x;
		std::cin >> x;
		if(x < 0) {
			tree.upd(tree.search(-x), -1);
		} else {
			tree.upd(x, 1);
		}
	}
	if(tree.qry(n) == 0) {
		std::cout << "0\n";
	} else {
		std::cout << tree.search(1) << '\n';
	}
}
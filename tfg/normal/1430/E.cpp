#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int _n) {
		this->n = _n;
		bit.assign(n + 1, 0);
	}

	void init(const std::vector<T> &a) {
		n = a.size();
		bit.assign(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
			if(i + (i & -i) <= n) {
				bit[i + (i & -i)] += bit[i];
			}
		}
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
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
	int n;
	std::vector<int> pos[26];
	std::string str;
	std::cin >> n >> str;
	std::reverse(str.begin(), str.end());
	for(int i = 0; i < n; i++) pos[str[i] - 'a'].push_back(n-i);
	FenwickTree<int> tree;
	tree.init(n+1);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int id = pos[str[i] - 'a'].back();
		pos[str[i] - 'a'].pop_back();
		ans += i - tree.qry(id);
		tree.upd(id, 1);
	}
	std::cout << ans << '\n';
}
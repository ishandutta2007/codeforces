#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
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

long long inversions(const std::vector<int> &a) {
	FenwickTree<int> tree;
	tree.init(a.size() + 10);
	long long ans = 0;
	int kek = 0;
	for(auto x : a) {
		ans += (kek++) - tree.qry(x+1);
		tree.upd(x+1, 1);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	std::string wtf = "ANTO";
	std::map<char, int> decod;
	for(int i = 0; i < 4; i++) decod[wtf[i]] = i;
	while(t--) {
		std::string str;
		std::cin >> str;
		std::vector<int> a[4];
		for(int i = 0; i < (int) str.size(); i++) {
			a[decod[str[i]]].push_back(i);
		}
		int p[4] = {0, 1, 2, 3};
		std::string ans;
		long long cost = -1;
		do {
			std::vector<int> haha;
			for(int i = 0; i < 4; i++) {
				for(auto x : a[p[i]]) {
					haha.push_back(x);
				}
			}
			auto inv = inversions(haha);
			if(inv > cost) {
				cost = inv;
				ans.clear();
				for(int i = 0; i < 4; i++) {
					for(auto x : a[p[i]]) {
						ans += wtf[p[i]];
					}
				}
			}
		} while(std::next_permutation(p, p+4));
		std::cout << ans << '\n';
	}
}
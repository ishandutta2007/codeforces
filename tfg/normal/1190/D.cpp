#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T>
class CoordinateCompression {
public:
	CoordinateCompression(const std::vector<T> &a) {
		arr = a;
		std::sort(arr.begin(), arr.end());
		arr.resize(std::unique(arr.begin(), arr.end()) - arr.begin());
	}

	int getL(T x) { return std::lower_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int getR(T x) { return std::upper_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int size() const { return (int) arr.size(); }
private:
	std::vector<T> arr;
};

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
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	std::vector<int> u;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].second >> a[i].first;
		a[i].first = -a[i].first;
		u.push_back(a[i].second);
	}
	CoordinateCompression<int> coord(u);
	std::sort(a.begin(), a.end());
	std::vector<bool> active(n+1, false);
	FenwickTree<int> tree;
	tree.init(n+1);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int pos = coord.getR(a[i].second);
		if(!active[pos]) {
			active[pos] = true;
			tree.upd(pos, 1);
		}
		int left = tree.qry(pos);
		int right = tree.qry(i+1 < n && a[i+1].first == a[i].first ? coord.getL(a[i+1].second) : n+1) - tree.qry(pos-1);
		ans += (long long) left * right;
		//std::cout << "at i == " << i << " got " << left << " * " << right << '\n';
	}
	std::cout << ans << '\n';
}
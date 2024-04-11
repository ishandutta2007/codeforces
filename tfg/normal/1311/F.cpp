#include <iostream>
#include <vector>
#include <chrono>
#include <random>
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
		x = std::min(x, n);
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
	std::vector<std::pair<int, int>> person(n);
	std::vector<int> uni(n);
	for(int i = 0; i < n; i++) {
		std::cin >> person[i].second;
		uni[i] = person[i].second;
	}
	CoordinateCompression<int> coord(uni);
	for(int i = 0; i < n; i++) {
		std::cin >> person[i].first;
	}
	std::sort(person.begin(), person.end());
	FenwickTree<int> freq;
	freq.init(n);
	FenwickTree<long long> sum;
	sum.init(n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int pos = coord.getR(person[i].second);
		ans += (long long) person[i].second * freq.qry(pos) - sum.qry(pos);
		freq.upd(pos, 1);
		sum.upd(pos, person[i].second);
	}
	std::cout << ans << std::endl;
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int nn) {
		this->n = nn;
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
	long long k;
	std::cin >> n >> k;
	std::vector<long long> sum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> sum[i];
		sum[i] += sum[i-1];
	}
	auto uni = sum;
	std::sort(uni.begin(), uni.end());
	uni.resize(std::unique(uni.begin(), uni.end()) - uni.begin());
	auto check = [&](long long x) {
		FenwickTree<int> tree;
		tree.init(n + 2);
		long long ans = 0;
		for(auto val : sum) {
			// looking for value <= val - x
			long long want = val - x;
			int id = std::upper_bound(uni.begin(), uni.end(), want) - uni.begin();
			ans += tree.qry(id);
			id = std::upper_bound(uni.begin(), uni.end(), val) - uni.begin();
			tree.upd(id, 1);
		}
		//std::cout << "at " << x << " got " << ans << std::endl;
		return ans;
	};
	long long l = -2e14, r = 2e14;
	while(l != r) {
		long long mid = l + (r - l + 1) / 2;
		if(check(mid) >= k) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << '\n';
}
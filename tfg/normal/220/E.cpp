#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int n) {
		this->n = n;
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
	long long INF;
	std::cin >> n >> INF;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> b = a;
	std::sort(b.begin(), b.end());
	for(int i = 0; i < n; i++) {
		a[i] = std::upper_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	FenwickTree<int> left, right;
	left.init(n);
	right.init(n);
	long long cur = 0;
	long long ans = 0;
	for(int l = 0, r = n; l + 1 < n; l++) {
		// include l
		cur += l - left.qry(a[l]);
		//std::cout << "added " << l - left.qry(a[l]) << " from left\n";
		cur += right.qry(a[l]-1);
		left.upd(a[l], 1);
		while(r <= l || (r < n && cur > INF)) {
			//std::cout << "(" << l << ", " << r << ")" << std::endl;
			cur -= (l+1) - left.qry(a[r]);
			cur -= right.qry(a[r]-1);
			right.upd(a[r], -1);
			r++;
		}
		//std::cout << "(" << l << ", " << r << ")" << std::endl;
		while(r > l && cur <= INF) {
			// include r
			r--;
			//std::cout << "(" << l << ", " << r << ")" << std::endl;
			cur += (l+1) - left.qry(a[r]);
			cur += right.qry(a[r]-1);
			right.upd(a[r], 1);
		}
		while(r <= l || (r < n && cur > INF)) {
			//std::cout << "(" << l << ", " << r << ")" << std::endl;
			cur -= (l+1) - left.qry(a[r]);
			cur -= right.qry(a[r]-1);
			right.upd(a[r], -1);
			r++;
		}
		//std::cout << "(" << l << ", " << r << ")" << std::endl;
		ans += std::max(0, n - r);
	}
	std::cout << ans << '\n';
}
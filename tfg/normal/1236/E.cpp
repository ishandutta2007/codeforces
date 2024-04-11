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
		x = std::min(x, n);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) x = 1;
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
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = 1;
	}
	long long ans = n;
	std::vector<int> b(m);
	for(auto &x : b) {
		std::cin >> x;
		x--;
	}
	for(int rep = 0; rep < 2; rep++) {
		FenwickTree<int> tree;
		tree.init(a);
		for(auto x : b) {
			int l = 1, r = n + 1;
			while(l != r) {
				int mid = (l + r) / 2;
				if(tree.qry(mid) < x) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			int low = l;
			l = 1, r = n + 1;
			while(l != r) {
				int mid = (l + r) / 2;
				if(tree.qry(mid) <= x) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			int up = l;
			tree.upd(1, 1);
			tree.upd(low, -1);
			tree.upd(up, 1);
		}
		for(int i = 0; i < n; i++) {
			//std::cout << "from " << i << " to " << std::min(n-1, tree.qry(i+1)) << '\n';
			int on = std::min(n-1, tree.qry(i+1));
			ans += (on - i);
		}
		//std::reverse(b.begin(), b.end());
		for(auto &x : b) {
			x = n - x - 1;
		}
	}
	if(n == 1) ans = 0;
	std::cout << ans << '\n';
}
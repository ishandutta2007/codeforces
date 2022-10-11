#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	FenwickTree(int s = 0) { init(s); }

	void init(int s) {
		this->n = s;
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

	int lift(T x) {
		int ans = 0;
		for(int i = 20; i >= 0; i--) {
			int toAns = ans | (1 << i);
			if(toAns > n) {
				continue;
			}
			if(bit[toAns] < x) {
				x -= bit[toAns];
				ans = toAns;
			}
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
	long long money;
	std::cin >> n >> money;
	long long ans = 0;
	FenwickTree<int> freq(n);
	FenwickTree<long long> sum(n);
	std::vector<int> a(n);
	long long tot = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		freq.upd(i + 1, 1);
		sum.upd(i + 1, a[i]);
		tot += a[i];
	}
	for(int rem = 0; rem < n; rem++) {
		//std::cout << "tot is " << tot << "\n";
		//std::cout << "money is " << money << "\n";
		//std::cout << "got " << money / tot << " full circles with " << n - rem << "\n";
		ans += money / tot * (n - rem);
		money %= tot;
		//std::cout << "remaining " << money << "\n";
		int idx = sum.lift(money + 1);
		//std::cout << "removing pos " << idx << "\n";
		tot -= a[idx];
		sum.upd(idx + 1, -a[idx]);
		freq.upd(idx + 1, -1);
	}
	std::cout << ans << "\n";
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 998244353;

long long fexp(long long x, long long e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

template <class T>
class FenwickTree {
public:
	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
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
	long long invs = 0;
	int n;
	std::cin >> n;
	std::vector<int> sum(n + 1, 0);
	std::vector<int> a(n + 1);
	int x = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] != -1) {
			sum[a[i]]++;
		} else {
			x++;
		}
	}
	for(int i = 1; i <= n; i++) {
		sum[i] += sum[i-1];
	}
	// (known, -1)
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == -1) {
			invs = (invs + count) % MOD;
		} else {
			// get numbers <
			//std::cout << "with number " << a[i] << ", got " << a[i] - sum[a[i]] << '\n';
			count = (count + (a[i] - sum[a[i]])) % MOD;
		}
	}
	//std::cout << "got " << invs << '\n';
	// (-1, known)
	count = 0;
	for(int i = n-1; i >= 0; i--) {
		if(a[i] == -1) {
			invs = (invs + count) % MOD;
		} else {
			// get numbers >
			count = (count - (sum[n] - sum[a[i]]) + (n - a[i])) % MOD;
			//std::cout << "with number " << a[i] << ", got " << sum[n] - sum[a[i]] + n - a[i] << '\n';
		}
	}
	//std::cout << "got " << invs << '\n';
	//std::cout << "(" << invs << " / " << x << " + " << x << " * " << x - 1 << " / " << 4 << ")\n";
	long long ans = (invs * fexp(x) + (long long) x * (x - 1) % MOD * fexp(4)) % MOD;
	FenwickTree<int> tree;
	tree.init(n + 1);
	for(int i = 0; i < n; i++) {
		if(a[i] == -1) continue;
		ans = (ans + tree.qry(n) - tree.qry(a[i])) % MOD;
		tree.upd(a[i], 1);
	}
	std::cout << ans << '\n';
}
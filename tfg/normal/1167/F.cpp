#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v >= MOD ? v - MOD : v) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
	void operator += (modBase<mod> o) { *this = *this + o; }
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
	std::vector<int> a(n);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	FenwickTree<modBase<>> treel, treer;
	treel.init(n + 10);
	treer.init(n + 10);
	modBase<> ans(0);
	for(int i = 0; i < n; i++) {
		treel.upd(p[i] + 1, p[i] + 1);
		treer.upd(p[i] + 1, n - p[i]);
		//std::cout << "solving " << a[p[i]] << " at position " << p[i] + 1 << '\n';
		// solving left
		//std::cout << "for left got " << treel.qry(p[i] + 1).val << " * " << modBase<>(n - p[i]).val << " * " << modBase<>(a[p[i]]).val << "\n";
		ans = ans + treel.qry(p[i] + 1) * modBase<>(n - p[i]) * modBase<>(a[p[i]]);
		// solving right
		ans = ans + (treer.qry(p[i] + 1) * modBase<>(MOD - 1) + treer.qry(n)) * modBase<>(p[i] + 1) * modBase<>(a[p[i]]);
	}
	std::cout << ans.val << '\n';
}
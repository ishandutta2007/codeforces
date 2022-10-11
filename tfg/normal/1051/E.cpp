#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct ZFunc {
	std::vector<int> z;
	ZFunc(const std::string v) : z(v.size()) {
		int n = (int) v.size(), a = 0, b = 0;
		if (!z.empty()) z[0] = n;
		for (int i = 1; i < n; i++) {
			int end = i; if (i < b) end = std::min(i + z[i - a], b);
			while(end < n && v[end] == v[end - i]) ++end;
			z[i] = end - i; if(end > b) a = i, b = end;
		}
	}
};

const int MOD = 998244353;

template <class T>
class FenwickTree {
public:
	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans = (ans + bit[x]) % MOD;
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] = (bit[x] + v) % MOD;
		}
	}
private:
	int n;
	std::vector<T> bit;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string a, l, r;
	std::cin >> a >> l >> r;
	ZFunc zl(l + '#' + a);
	ZFunc zr(r + '#' + a);
	FenwickTree<int> dp;
	int n = (int) a.size();
	dp.init(n + 1);
	dp.upd(1, 1);
	dp.upd(2, MOD - 1);
	for(int i = 0; i + (int) l.size() <= n; i++) {
		int cur = dp.qry(i + 1);
		//std::cout << "cur for " << i << " is " << cur << std::endl;
		if(a[i] == '0' && (int) l.size() == 1 && l[0] == '0') {
			dp.upd(i + 2, cur);
			dp.upd(i + 3, (MOD - cur) % MOD);
		}
		if(a[i] == '0' || cur == 0) {
			continue;
		}
		int pr = std::min((int) r.size(), n - i);
		//std::cout << "pr is " << pr << " and zr is " << zr.z[(int) r.size() + i + 1] << std::endl;
		if(pr == (int) r.size() && zr.z[(int) r.size() + i + 1] < (int) r.size() && r[zr.z[i + (int) r.size() + 1]] < a[i + zr.z[i + (int) r.size() + 1]]) {
			pr--;
		}
		int pl = (int) l.size();
		//std::cout << "pl is " << pl << " and zl is " << zl.z[(int) l.size() + i + 1] << std::endl;
		if(zl.z[(int) l.size() + i + 1] < pl && a[i + zl.z[(int) l.size() + i + 1]] < l[zl.z[(int) l.size() + i + 1]]) {
			pl++;
		}
		if(pl <= pr) {
			//std::cout << "on " << i << " got range [" << pl << ", " << pr << "]\n";
			dp.upd(i + pl + 1, cur);
			dp.upd(i + pr + 2, MOD - cur);
		}
	}
	std::cout << dp.qry(n + 1) << std::endl;
}
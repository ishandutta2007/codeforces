#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Range {
	int l, r, val;
	Range() {}
	Range(int a, int b, int c) : l(a), r(b), val(c) {}
};

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

const int MOD = 1e9 + 7;
template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

modBase<> comb(int n, int a) {
	if(a < 0 || a > n) return 0;
	n %= MOD;
	if(a < 0 || a > n) return 0;
	modBase<> ans(1);
	for(int i = 0; i < a; i++) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, p;
	std::cin >> n >> p;
	std::vector<Range> dp;
	dp.emplace_back(1, std::min(p, 3), 0);
	for(int i1 = 0, i2 = 0; dp.back().r < p; ) {
		int l = dp.back().r;
		while(l / 3 >= dp[i1].r) i1++;
		while(l - l / 3 >= dp[i2].r) i2++;
		int r = p;
		auto check = [&](int x) { return x / 3 < dp[i1].r && x - x / 3 < dp[i2].r; };
		while(l != r) {
			int mid = (l + r) / 2;
			if(check(mid)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		int mask = 0;
		mask |= 1 << dp[i1].val;
		mask |= 1 << dp[i2].val;
		int ans = 0;
		while(mask & (1 << ans)) ans++;
		if(dp.back().val != ans) {
			dp.emplace_back(dp.back().r, l, ans);
		} else {
			dp.back().r = l;
		}
	}
	modBase<> freq[3] = {0, 0, 0};
	for(auto range : dp) {
		//std::cout << "[" << range.l << ", " << range.r << ") = " << range.val << '\n';
		assert(range.val <= 2);
		//std::cout << (range.r - range.l) * ((p - range.l) + (p - (range.r-1))) / 2 << '\n';
		freq[range.val] += modBase<>(range.r - range.l) * ((p - range.l) + (p - (range.r-1))) / 2;
	}
	//std::cout << "freqs (" << freq[0] << ", " << freq[1] << ", " << freq[2] << ")\n";
	std::vector<std::vector<modBase<>>> ans(n+1, std::vector<modBase<>>(4, 0));
	ans[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int x = 0; x < 4; x++) {
			for(int y = 0; y < 3; y++) {
				ans[i+1][x^y] += ans[i][x] * freq[y];
			}
		}
	}
	std::cout << ans[n][1] + ans[n][2] + ans[n][3] << '\n';
}
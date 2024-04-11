#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 1010;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

modBase<> cnt[ms];
modBase<> pref[ms], suf[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	cnt[0] = 1;
	for(int i = 1; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			cnt[j] += cnt[j-1];
		}
	}
	for(int i = 1; i <= n; i++) {
		//std::cout << "count for " << i << " is " << cnt[i-1].val << std::endl;
		for(int j = i; j <= n; j++) {
			pref[j] += cnt[j-i];
			suf[n-j+1] += cnt[j-i];
		}
	}
	modBase<> ans;
	for(int i = 1; i <= n; i++) {
		pref[i] += pref[i-1];
		ans += pref[i] * suf[i];
	}
	std::cout << ans.val << std::endl;
}
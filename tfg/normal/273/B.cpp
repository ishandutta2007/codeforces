#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

int mod;
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase o) { *this = *this + o; }
	void operator -= (modBase o) { *this = *this - o; }
	void operator *= (modBase o) { *this = *this * o; }
	modBase operator * (modBase o) { return (int)((long long) val * o.val % mod); }
	modBase operator + (modBase o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase operator - (modBase o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase &p) {
		return is >> p.val;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<int, std::vector<int>> mp;
	int n;
	std::cin >> n;
	for(int rep = 0; rep < 2; rep++) {
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			mp[x].push_back(i);
		}
	}
	std::cin >> mod;
	std::vector<int> pot(2*n+1, 0);
	std::vector<modBase> fat(2*n+1, 1), val(2*n+1, 1);
	for(int i = 1; i <= 2*n; i++) {
		val[i] = i % 2 == 0 ? val[i / 2] : i;
		fat[i] = fat[i-1] * val[i];
		pot[i] = pot[i / 2] + i / 2;
	}
	modBase ans(1);
	for(auto it : mp) {
		auto a = it.second;
		ans *= fat[a.size()];
		std::sort(a.begin(), a.end());
		ans *= fexp(modBase(2), pot[a.size()] - (a.end() - std::unique(a.begin(), a.end())));
	}
	std::cout << ans << '\n';
}
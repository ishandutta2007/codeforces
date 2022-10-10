#include <iostream>
#include <vector>
#include <chrono>
#include <random>

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

template <int mod = 998244353>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int sum = 0;
	const int ms = 1e6 + 10;
	std::vector<modBase<>> f(ms, 0), g(ms, 0);
	//std::vector<double> f(ms, 0), g(ms, 1);
	for(int i = 0; i < n; i++) {
		int size;
		std::cin >> size;
		modBase<> prob = modBase<>(1) / size / n;
		//double prob = 1.0 / size / n;
		while(size--) {
			int x;
			std::cin >> x;
			x--;
			f[x] = f[x] + prob;
			//g[x] = g[x] - 1.0 / n;
			g[x] = g[x] + modBase<>(1) / n;
			sum++;
		}
	}
	modBase<> ans;
	//double ans = 0;
	for(int i = 0; i < ms; i++) {
		//if(f[i] == 0) continue;
		//std::cout << f[i] << ' ' << g[i] << '\n';
		ans = ans + f[i] * g[i];
	}
	//std::cout << ans << '\n';
	std::cout << ans.val << '\n';
}
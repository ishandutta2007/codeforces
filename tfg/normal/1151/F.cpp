#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int val = 0) : val((val % mod + mod) % mod) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return modBase<mod>((long long) val * o.val % mod); }
	modBase<mod> operator + (modBase<mod> o) { return modBase<mod>((val+o.val)%mod); }
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

template<const size_t n, const size_t m, class T = modBase<>>
struct Matrix {
	T v[n][m];
	
	Matrix(int d = 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				v[i][j] = T(0);
			}
			if(i < m) {
				v[i][i] = T(d);
			}
		}
	}
	
	template<size_t mm>
	Matrix<n, mm, T> operator *(Matrix<m, mm, T> &o) {
		Matrix<n, mm, T> ans;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < mm; j++) {
				for(int k = 0; k < m; k++) {
					ans.v[i][j] = ans.v[i][j] + v[i][k] * o.v[k][j];
				}
			}
		}
		return ans;
	}
};

int pairs(int x) { return x * (x - 1) / 2; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int freq[2] = {0, 0};
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		freq[a[i]]++;
	}
	const int ms = 101;
	Matrix<ms, ms> bas(0);
	for(int i = 0; i <= freq[0]; i++) {
		int z0 = i, o0 = freq[0] - i;
		int z1 = freq[0] - z0, o1 = freq[1] - o0;
		if(o0 < 0 || o1 < 0 || z0 < 0 || z1 < 0) continue;
		if(z0 + z1 != freq[0] || o0 + o1 != freq[1]) continue;
		if(z0 + o0 != freq[0] || z1 + o1 != freq[1]) continue;
		//std::cout << "state (" << z0 << ", " << o0 << "), (" << z1 << ", " << o1 << ")\n";
		auto p = fexp(modBase<>(pairs(n)), MOD - 2);
		// z0 o0, z1 o1
		bas.v[i][i] = p * modBase<>(z0 * o0 + z1 * o1 + z0 * z1 + o0 * o1 + pairs(z0) + pairs(z1) + pairs(o0) + pairs(o1));
		if(z0 > 0 && o1 > 0) {
			// z0 o1
			bas.v[i][i-1] = p * modBase<>(z0 * o1);
		}
		if(o0 > 0 && z1 > 0) {
			// z1 o0
			bas.v[i][i+1] = p * modBase<>(z1 * o0);
		}
	}
	auto ans = fexp(bas, k);
	int z0 = 0;
	for(int i = 0; i < freq[0]; i++) {
		if(a[i] == 0) z0++;
	}
	std::cout << ans.v[z0][freq[0]].val << '\n';
}
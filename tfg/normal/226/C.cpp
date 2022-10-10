#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mod;

struct modBase {
	modBase(int val = 0) : val(val%mod) {}
	int val;

	modBase operator * (modBase o) { return (long long) val * o.val % mod; }
	modBase operator + (modBase o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
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

template<const size_t n, const size_t m, class T = modBase>
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long m, l, r, k;
	std::cin >> m >> l >> r >> k;
	mod = m;
	l--;
	long long ans = 0;
	for(long long ll = 1, rr; ll <= r; ll = rr + 1) {
		rr = r / (r / ll);
		if(l / ll > 0) {
			rr = std::min(rr, l / (l / ll));
		}
		long long got = (r / ll - l / ll);
		if(got >= k) {
			ans = rr;
		}
	}
	Matrix<2, 2> base;
	base.v[1][1] = 0;
	base.v[0][1] = base.v[1][0] = base.v[0][0] = 1;
	std::cout << fexp(base, ans).v[1][0].val << '\n';
}
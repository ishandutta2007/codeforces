#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mod;

struct modBase {
	modBase(int val = 0) : val(val) {}
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
	unsigned long long n, k;
	int l;
	std::cin >> n >> k >> l >> mod;
	int bits = 0;
	for(int i = 0; i < l; i++) {
		if((k >> i) & 1) {
			bits++;
		}
	}
	for(int i = l; i < 64; i++) {
		if((k >> i) & 1) {
			std::cout << "0\n";
			return 0;
		}
	}
	Matrix<2, 2, modBase> base0(0);
	base0.v[0][0] = 1;
	base0.v[0][1] = 1;
	base0.v[1][0] = 1;
	modBase ans0 = fexp(base0, n).v[0][0] + fexp(base0, n).v[1][0];
	Matrix<3, 3, modBase> base1(0);
	base1.v[0][0] = 1;
	base1.v[0][1] = 1;
	base1.v[1][0] = 1;
	base1.v[2][1] = 1;
	base1.v[2][2] = 2;
	modBase ans1 = fexp(base1, n).v[2][0];
	//std::cout << "ans0 is " << ans0.val << '\n';
	//std::cout << "ans1 is " << ans1.val << '\n';
	//std::cout << "freqs (" << l - bits << ", " << bits << ")\n";
	modBase ans = fexp(ans0, l - bits) * fexp(ans1, bits);
	std::cout << ans.val << '\n';
}
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int val = 0) : val(val) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
};

template<const size_t n, const size_t m, class T = modBase<>>
struct Mat {
	T v[n][m];
	
	Mat(int d = 0) {
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
	Mat<n, mm, T> operator *(Mat<m, mm, T> &o) {
		Mat<n, mm, T> ans;
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



template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// {sum, worlds}
	// {4 * sum - worlds, 2 * worlds}
	Mat<2, 2> base;
	base.v[0][0] = 4;
	base.v[0][1] = MOD - 1;
	base.v[1][1] = 2;
	long long n, k;
	std::cin >> n >> k;
	if(n == 0) {
		std::cout << "0\n";
		return 0;
	}
	n %= MOD;
	auto end = fexp<Mat<2, 2>>(base, k);
	Mat<2, 1> col;
	col.v[0][0] = n;
	col.v[1][0] = 1;
	col = end * col;
	long long sum = col.v[0][0].val;
	long long worlds = col.v[1][0].val;
	sum = 2 * sum % MOD;
	sum = sum * fexp<modBase<MOD>>(worlds, MOD - 2).val % MOD;
	std::cout << sum << std::endl;
}
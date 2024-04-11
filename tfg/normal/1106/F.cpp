#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int root = 3;

int trans[100100];
std::map<int, int> first;

int solve(int en) {
	if(root == en) return 1;
	if(en == 1) return 0;
	int step = sqrt(MOD) + 10;
	trans[0] = 1;
	for(int i = 1; i <= step; i++) {
		trans[i] = (long long) trans[i - 1] * root % MOD;
		if(trans[i] == en) return i;
	}
	if(first.empty()) {
		int lst = 0;
		int val = 1;
		for(int i = 0; lst - step <= MOD; i++) {
			if(!first.count(val)) {
				first[val] = lst;
				//std::cout << "inserting " << val << " at pos " << lst << "\n";
			}
			lst += step;
			val = (long long) val * trans[step] % MOD;
		}
	}
	for(int i = 0; i <= step; i++) {
		if(first.count(en)) {
			return (MOD - 1 - i + first[en]) % (MOD - 1);
		}
		en = (long long) en * root % MOD;
	}
	assert(false);
	return -1;
}

template <int mod = MOD>
struct modBase {
	modBase(int val = 0) : val(val) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
};

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

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

long long modinverse(long long a, long long b, long long s0 = 1, long long s1 = 0) {
    //std::cout << "on (" << a << ", " << b << ", " << s0 << ", " << s1 << ")\n";
    if(!b)
        return s0;
    else
        return modinverse(b, a % b, s1, s0 - s1 * (a / b));
}

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int k;
	std::cin >> k;
	std::vector<int> b(k);
	for(int i = 0; i < k; i++) {
		std::cin >> b[i];
	}
	Matrix<100, 100, modBase<MOD - 1> > mat;
	for(int i = 0; i < k; i++) {
		mat.v[0][i] = b[i];
	}
	for(int i = 1; i < k; i++) {
		mat.v[i][i-1] = 1;
	}
	int n, val;
	std::cin >> n >> val;
	auto end = fexp(mat, n - k);
	int tot = end.v[0][0].val;
	int id = solve(val);
	//std::cout << "got " << id << ", " << fexp(modBase<MOD>(root), id).val << " == " << val << '\n';
	//tot * x == id mod (MOD-1)
	//x == id * tot^-1 (MOD-1)
	long long g = gcd(id, tot);
	if(g == 0) g = 1;
	long long x = (id/g) * modinverse(tot/g, MOD - 1) % (MOD - 1);
	x = (x + MOD - 1) % (MOD - 1);
	long long ans = fexp(modBase<MOD>(root), x).val;
	//std::cout << "suposed answer is " << ans << "\n";
	if(fexp(modBase<MOD>(ans), tot).val == val) {
		std::cout << ans << '\n';
	} else {
		std::cout << "-1\n";
	}
}
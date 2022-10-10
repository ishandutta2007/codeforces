#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;

	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
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

template<const char T>
std::vector<modBase<>> FWHT(std::vector<modBase<>> a, const bool inv = false) {
	int n = (int) a.size();
	for(int len = 1; len < n; len += len) {
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				auto u = a[i + j], v = a[i + j + len];
				if(T == '^') {
					a[i + j] = u + v;
					a[i + j + len] = u - v;
				}
				if(T == '|') {
					if(!inv) {
						a[i + j + len] += a[i + j];
					} else {
						a[i + j + len] -= a[i + j];
					}
				}
				if(T == '&') {
					if(!inv) {
						a[i + j] += a[i + j + len];
					} else {
						a[i + j] -= a[i + j + len];
					}
				}
			}
		}
	}
	if(T == '^' && inv) {
		modBase<> rev = fexp(modBase<>(n), MOD - 2);
		for(int i = 0; i < n; i++) {
			a[i] = a[i] * rev;
		}
	}
	return a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int me = 17;
	const int ms = 1 << me;
	std::vector<int> bits(ms, 0);
	for(int i = 1; i < ms; i++) {
		bits[i] = bits[i >> 1] + (i & 1);
	}
	std::vector<modBase<>> freq(ms, 0), f(ms, 0);
	f[1] = 1;
	for(int i = 2; i < ms; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	{
		int n;
		std::cin >> n;
		while(n--) {
			int x;
			std::cin >> x;
			freq[x] += 1;
		}
	}
	// solving first or
	std::vector<modBase<>> A(ms, 0);
	{
		std::vector<std::vector<modBase<>>> table(me+1, std::vector<modBase<>>(ms, 0));
		for(int i = 0; i < ms; i++) {
			table[bits[i]][i] += freq[i];
		}
		for(int i = 0; i <= me; i++) {
			table[i] = FWHT<'|'>(table[i]);
		}
		for(int sum = 0; sum <= me; sum++) {
			std::vector<modBase<>> B(ms, 0);
			for(int i = 0; i <= sum; i++) {
				int j = sum - i;
				for(int k = 0; k < ms; k++) {
					B[k] += table[i][k] * table[j][k];
				}
			}
			B = FWHT<'|'>(B, true);
			for(int i = 0; i < ms; i++) {
				if(bits[i] != sum) {
					B[i] = 0;
				}
				B[i] *= f[i];
			}
			for(int i = 0; i < ms; i++) {
				A[i] += B[i];
			}
		}
	}
	A = FWHT<'&'>(A);
	// solving second
	{
		auto B = freq;
		for(int i = 0; i < ms; i++) {
			B[i] *= f[i];
		}
		B = FWHT<'&'>(B);
		for(int i = 0; i < ms; i++) {
			A[i] *= B[i];
		}
	}
	// solving third xor
	{
		auto B = FWHT<'^'>(freq);
		for(int i = 0; i < ms; i++) {
			B[i] *= B[i];
		}
		B = FWHT<'^'>(B, true);
		for(int i = 0; i < ms; i++) {
			B[i] *= f[i];
		}
		B = FWHT<'&'>(B);
		for(int i = 0; i < ms; i++) {
			A[i] *= B[i];
		}
	}
	A = FWHT<'&'>(A, true);
	modBase<> ans(0);
	for(int i = 0; i < me; i++) {
		ans = ans + A[1<<i];
	}
	std::cout << ans.val << '\n';
}
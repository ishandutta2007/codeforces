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

struct Info {
	modBase<> sum, sum2, freq;

	Info() {
		sum = sum2 = freq = 0;
	}

	void apply(modBase<> x) {
		sum += x;
		sum2 += x * x;
		freq += 1;
	}

	Info operator + (Info o) {
		Info ans;
		ans.sum = sum + o.sum;
		ans.sum2 = sum2 + o.sum2;
		ans.freq = freq + o.freq;
		return ans;
	}

	Info operator - (Info o) {
		Info ans;
		ans.freq = freq - o.freq;
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1000000;
	int n;
	std::cin >> n;
	std::vector<Info> a(ms);
	while(n--) {
		int x;
		std::cin >> x;
		a[x].apply(x);
	}
	for(int len = 1; len < ms; len *= 10) {
		for(int i = 0; i < ms; i += len * 10) {
			for(int j = 0; j < len; j++) {
				for(int k = 10-2; k >= 0; k--) {
					a[i+j+len*k] = a[i+j+len*k] + a[i+j+len*(k+1)];
				}
			}
		}
	}
	for(int i = 0; i < ms; i++) {
		modBase<> same = a[i].sum2, diff = a[i].sum * a[i].sum - a[i].sum2;
		modBase<> got = 0;
		if(a[i].freq.val >= 1) {
			got += fexp(modBase<>(2), a[i].freq.val - 1) * same;
		}
		if(a[i].freq.val >= 2) {
			got += fexp(modBase<>(2), a[i].freq.val - 2) * diff;
		}
		a[i].freq = got;
	}
	
	for(int len = 1; len < ms; len *= 10) {
		for(int i = 0; i < ms; i += len * 10) {
			for(int j = 0; j < len; j++) {
				for(int k = 0; k+1 < 10; k++) {
					a[i+j+len*k] = a[i+j+len*k] - a[i+j+len*(k+1)];
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < ms; i++) {
		ans ^= (long long) a[i].freq.val * i;
	}
	std::cout << ans << '\n';
}
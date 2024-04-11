#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

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
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	//void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

const int me = 14;
const int ms = 1 << me;

modBase<> winProb[me][me];
modBase<> winMask[ms][me];
modBase<> sccDP[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) winProb[i][j] = modBase<>(a[i]) / (a[i] + a[j]);
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) {
			winMask[mask][i] = 1;
			for(int j = 0; j < n; j++) {
				if(mask & (1 << j)) {
					winMask[mask][i] *= winProb[i][j];
				}
			}
		}
	}
	// calculate sccDP
	sccDP[0] = 1;
	for(int mask = 1; mask < (1 << n); mask++) {
		sccDP[mask] = 1;
		for(int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
			if(subMask == mask) continue;
			// subMask == top component
			// other == rest
			// edges from subMask to others
			int other = subMask ^ mask;
			modBase<> trans = sccDP[subMask];
			for(int i = 0; i < n; i++) if(subMask & (1 << i)) {
				trans *= winMask[other][i];
			}
			sccDP[mask] -= trans;
		}
	}
	// calculate answer
	modBase<> ans(0);
	for(int mask = 1; mask < (1 << n); mask++) {
		modBase<> trans = sccDP[mask];
		int other = ((1 << n) - 1) ^ mask;
		int cnt = 0;
		for(int i = 0; i < n; i++) if(mask & (1 << i)) {
			trans *= winMask[other][i];
			cnt++;
		}
		ans += trans * cnt;
	}
	std::cout << ans << '\n';
}
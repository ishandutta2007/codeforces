#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int N, class T = unsigned int>
class XorGauss {
public:
	XorGauss() {
		for(int i = 0; i < N; i++) { a[i] = 0; }
	}
	T reduce(T x) {
		for(int i = N-1; i >= 0; i--) {
			x = std::min(x, x ^ a[i]);
		}
		return x;
	}

	T augment(T x) { return ~reduce(~x); }

	bool add(T x) {
		for(int i = N-1; i >= 0; i--) {
			if((x & (((T)1) << i)) == 0) { continue; }
			if(a[i]) {
				x ^= a[i];
			} else {
				a[i] = x;
				for(int j = i-1; j >= 0; j--) {
					a[i] = std::min(a[i], a[i] ^ a[j]);
				}
				for(int j = i+1; j < N; j++) {
					a[j] = std::min(a[j], a[j] ^ a[i]);
				}
				return true;
			}
		}
		return false;
	}

	std::vector<T> getWeird() {
		//for(int i = 0; i < N; i++) {
		//	if(a[i]) std::cout << a[i] << ' ';
		//}std::cout << '\n';
		std::vector<int> good;
		for(int i = 0; i < N; i++) {
			if(a[i]) continue;
			bool ha = true;
			for(int j = 0; j < N; j++) {
				ha = ha || (a[j] & (1LL << j)) == 0;
			}
			if(ha) good.push_back(i);
		}
		std::vector<T> ans;
		for(int i = 0; i < N; i++) {
			if(!a[i]) continue;
			ans.push_back(0);
			for(int j = 0; j < (int) good.size(); j++) {
				if(a[i] & (1LL << good[j])) {
					ans.back() |= 1LL << j;
				}
			}
			//std::cout << ans.back() << ' ';
		}//std::cout << '\n';
		return ans;
	}
private:
	T a[N];
};

typedef XorGauss<60, long long> Gauss;

const long long MOD = 998244353;
const int ms = 1 << 20;

int bitTable[ms];

int getBits(long long x) {
	if(x < ms) return bitTable[x & (ms-1)];
	else return bitTable[x & (ms-1)] + getBits(x >> 20);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		bitTable[i] = bitTable[i/2] + i % 2;
	}
	int n, m;
	std::cin >> n >> m;
	long long other = 1;
	Gauss gauss;
	while(n--) {
		long long x;
		std::cin >> x;
		if(!gauss.add(x)) {
			other = other * 2 % MOD;
		}
	}
	auto base = gauss.getWeird();
	long long mx = 0;
	for(auto x : base) mx = std::max(mx, x);
	std::vector<long long> ans(m + 1, 0);
	if((int) base.size() < 22) {
		//std::cout << "first!\n";
		std::vector<long long> got(1, 0);
		for(auto x : base) {
			for(int i = 0, tot = (int) got.size(); i < tot; i++) {
				got.push_back(got[i] ^ x);
			}
		}
		for(int i = 0; i < (int) got.size(); i++) {
			ans[getBits(i) + getBits(got[i])]++;
		}
	} else {
		//std::cout << "second!\n";
		assert(mx <= (1 << 20));
		int ha = 1;
		while(ha <= (int) mx) ha += ha;
		std::vector<std::vector<long long>> dp(base.size() + 1, std::vector<long long>(ha, 0));
		dp[0][0] = 1;
		int c = 0;
		for(auto x : base) {
			for(int cnt = c++; cnt >= 0; cnt--) {
				for(int i = 0; i < ha; i++) {
					int j = i ^ (int) x;
					dp[cnt+1][i] = (dp[cnt+1][i] + dp[cnt][j]) % MOD;
				}
			}
		}
		for(int i = 0; i <= c; i++) {
			for(int j = 0; j < ha; j++) {
				int bits = i + getBits(j);
				//std::cout << "with " << i << " got " << dp[i][j] << " ways to get " << j << ", has " << bits << " bits\n";
				ans[bits] = (ans[bits] + dp[i][j]) % MOD;
			}
		}
	}
	for(int i = 0; i <= m; i++) {
		std::cout << ans[i] * other % MOD << (i == m ? '\n' : ' ');
	}
}
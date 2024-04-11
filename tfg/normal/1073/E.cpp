#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int ll

typedef long long ll;

const int MOD = 998244353;
const int md = 20;
const int mm = 1 << 10;

int k;
int pot[md], bits[mm];
bool visit[md][mm];
std::pair<int, int> memo[md][mm];

void add(std::pair<int, int> &a, std::pair<int, int> b, long long x = 0) {
	// first is sum
	// second is count
	a.first = (a.first + b.first + x * b.second) % MOD;
	a.second = (a.second + b.second) % MOD;
}

std::pair<int, int> dp(int x, int mask) {
	if(x == 0) {
		return std::pair<int, int> (0, (mask > 0 && bits[mask] <= k) ? 1 : 0);
	}
	std::pair<int, int> &ans = memo[x][mask];
	if(visit[x][mask]) return ans;
	visit[x][mask] = true;
	ans = {0, 0};
	if(mask == 0) {
		add(ans, dp(x - 1, 0));
		for(int i = 1; i < 10; i++) {
			add(ans, dp(x - 1, 1 << i), (long long) pot[x - 1] * i % MOD);
		}
	} else {
		for(int i = 0; i < 10; i++) {
			add(ans, dp(x - 1, mask | (1 << i)), (long long) pot[x - 1] * i % MOD);
		}
	}
	return ans;
}

int solve(long long x) {
	if(x <= 0) return 0;
	std::vector<long long> digits;
	while(x > 0) {
		digits.push_back((int) (x % 10));
		x /= 10;
	}
	std::reverse(digits.begin(), digits.end());
	int ans = dp((int) digits.size() - 1, 0).first;
	int mask = 0;
	int curSum = 0;
	for(int i = 0; i < (int) digits.size(); i++) {
		for(int j = (i == 0 ? 1 : 0); j < digits[i]; j++) {
			auto cur = dp((int) digits.size() - i - 1, mask | (1 << j));
			ans = (ans + cur.first) % MOD;
			ans = (ans + (long long) cur.second * pot[(int) digits.size() - i - 1] % MOD * j % MOD) % MOD;
			ans = (ans + (long long) curSum * cur.second) % MOD;
		}
		curSum = (curSum + pot[(int) digits.size() - i - 1] * digits[i]) % MOD;
		mask |= 1 << digits[i];
	}
	if(bits[mask] <= k) {
		ans = (ans + curSum) % MOD;
	}
	return ans;
}

main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long l, r;
	std::cin >> l >> r >> k;
	for(int i = 1; i < mm; i++) {
		bits[i] = bits[i / 2] + i % 2;
	}
	pot[0] = 1;
	for(int i = 1; i < md; i++) {
		pot[i] = (long long) pot[i - 1] * 10 % MOD;
	}
	std::cout << ((solve(r) - solve(l - 1)) % MOD + MOD) % MOD << '\n';
}
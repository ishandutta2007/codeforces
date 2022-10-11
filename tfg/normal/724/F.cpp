#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int mod;

template <class T>
T fexp(T x, int e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

struct modBase {
	modBase(int v = 0) : val((v % mod + mod) % mod) {}
	int val;

	modBase operator * (modBase o) { return (long long) val * o.val % mod; }
	modBase operator / (modBase o) { return *this * fexp(o, mod - 2); }
	modBase operator + (modBase o) { return modBase((val + o.val) % mod); }
};

int d;
const int ms = 1010;
modBase ifat[ms];
bool visit[ms][ms][22];
modBase memo[ms][ms][22];
modBase trans(int on, int sum, int rest) {
	if(rest == 0) return sum == 0 ? modBase(1) : modBase(0);
	if(sum < 0 || on == 0) return modBase(0);
	modBase &ans = memo[on][sum][rest];
	if(visit[on][sum][rest]) return ans;
	visit[on][sum][rest] = true;
	ans = 0;
	modBase cur(1);
	modBase ha = on == 1 ? modBase(1) : trans(on-1, on-1, d-1);
	for(int i = 0; i <= rest && cur.val; i++) {
		ans = ans + ifat[i] * cur * trans(on - 1, sum - on * i, rest - i);
		cur = cur * ha;
		ha = ha + 1;
	}
	return ans;
}

modBase haha(modBase x) {
	return x * (x + 1) / 2;
}

modBase dp(int n) {
	if(n == 1 || n == 2) return modBase(1);
	//else if(1) return trans(n/2, n-1, d);
	else return trans((n-1)/2, n-1, d) + ((n - 2) % 2 == 0 ? haha(trans(n / 2 - 1, n / 2 - 1, d-1)) : modBase(0));
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> d >> mod;
	ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		ifat[i] = ifat[i-1] * fexp(modBase(i), mod - 2);
	}
	std::cout << dp(n).val % mod << '\n';
}
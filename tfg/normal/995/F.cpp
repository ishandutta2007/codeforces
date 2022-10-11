#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;
const int MOD = 1e9 + 7;

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

long long fat[ms], ifat[ms];

class LagrangePoly {
public:
	LagrangePoly(std::vector<long long> _a) {
		//f(i) = _a[i]
		//interpola o vetor em um polinomio de grau y.size() - 1
		y = _a;
		den.resize(y.size());
		int n = (int) y.size();
		for(int i = 0; i < n; i++) {
			y[i] = (y[i] % MOD + MOD) % MOD;
			den[i] = ifat[n - i - 1] * ifat[i] % MOD;
			if((n - i - 1) % 2 == 1) {
				den[i] = (MOD - den[i]) % MOD;
			}
		}
	}
	
	long long getVal(long long x) {
		int n = (int) y.size();
		x %= MOD;
		if(x < n) {
			//return y[(int) x];
		}
		std::vector<long long> l, r;
		l.resize(n);
		l[0] = 1;
		for(int i = 1; i < n; i++) {
			l[i] = l[i - 1] * (x - (i - 1) + MOD) % MOD;
		}
		r.resize(n);
		r[n - 1] = 1;
		for(int i = n - 2; i >= 0; i--) {
			r[i] = r[i + 1] * (x - (i + 1) + MOD) % MOD;
		}
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long coef = l[i] * r[i] % MOD;
			ans = (ans + coef * y[i] % MOD * den[i]) % MOD;
		}
		return ans;
	}
	
private:
	std::vector<long long> y, den;
};

std::vector<int> edges[ms];
int dp[ms][ms];
void go(int on) {
	for(int i = 1; i < ms; i++) {
		dp[on][i] = 1;
	}
	for(auto to : edges[on]) {
		go(to);
		for(int i = 1; i < ms; i++) {
			dp[on][i] = (long long) dp[on][i] * dp[to][i] % MOD;
		}
	}
	for(int i = 2; i < ms; i++) {
		dp[on][i] = (dp[on][i] + dp[on][i - 1]) % MOD;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	int n, d;
	std::cin >> n >> d;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p-1].push_back(i);
	}
	go(0);
	std::vector<long long> v;
	for(int i = 0; i < ms; i++) {
		v.push_back(dp[0][i]);
	}
	LagrangePoly poly(v);
	std::cout << poly.getVal(d) << '\n';
}
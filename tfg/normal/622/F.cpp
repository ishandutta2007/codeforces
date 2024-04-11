#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

const int ms = 1001000;
const long long MOD = 1e9 + 7;

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
		//O(N^2)
		/*long long ans = 0;
		for(int i = 0; i < n; i++) {
			long long cur = den[i];
			for(int j = 0; j < n; j++) {
				if(i == j) { continue; }
				cur = cur * (x - y[i] + MOD) % MOD;
			}
			ans = (ans + cur) % MOD;
		}
		return ans;*/
		// O(N)
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

int main(){
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	// Codeforces 622F
	int x, k;
	std::cin >> x >> k;
	std::vector<long long> a;
	a.push_back(0);
	for(long long i = 1; i <= k + 1; i++) {
		a.push_back((a.back() + fexp(i, k)) % MOD);
	}
	LagrangePoly f(a);
	std::cout << f.getVal(x) << '\n';
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef unsigned long long ull;
typedef long double ld;

ull fmul(ull a, ull b, ull m) {
	ull q = (ld) a * (ld) b / (ld) m;
	ull r = a * b - q * m;
	return (r + m) % m;
}

long long fexp(ull x, ull e, ull m) {
	ull ans = 1;
	x = x % m;
	for(; e; e >>= 1) {
		if(e & 1) {
			ans = fmul(ans, x, m);
		}
		x = fmul(x, x, m);
	}
	return (long long) ans;
}

long long solve(long long val, long long mod, const std::vector<long long> &primes, const std::vector<long long> &primes2) {
	val %= mod;
	long long cyc = mod;
	for(auto p : primes) {
		if(mod % p == 0) {
			cyc = cyc / p * (p - 1);
		}
	}
	long long ans = cyc;
	for(auto p : primes2) {
		while(ans % p == 0 && fexp(val, ans / p, mod) == 1) {
			ans /= p;
		}
	}
	assert(ans <= cyc);
	//std::cout << "(" << val << ", " << mod << ") has cycle of size " << ans << ", adding " << cyc / ans << '\n';
	return cyc / ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long ans = 1;
	long long m, x;
	std::cin >> m >> x;
	if(0) {
		int kek = 1;
		std::vector<bool> haha((int) m+1, false);
		for(int i = 1; i < m; i++) {
			if(haha[i]) continue;
			kek++;
			for(int j = i; !haha[j]; j = j * (int) x % (int) m) {
				std::cout << j << ' ';
				haha[j] = true;
			}
			std::cout << '\n';
		}
		std::cout << "should be " << kek << '\n';
	}
	long long mod = m;
	long long tot = m;
	std::vector<long long> primes, primes2;
	for(long long i = 2; i * i <= m; i++) {
		if(m % i == 0) {
			while(m % i == 0) {
				m /= i;
			}
			tot /= i;
			tot *= (i - 1);
			primes.push_back(i);
		}
	}
	if(m != 1) {
		tot /= m;
		tot *= m - 1;
		primes.push_back(m);
	}
	m = mod;
	long long wtf = tot;
	for(long long i = 2; i * i <= m; i++) {
		if(wtf % i == 0) {
			while(wtf % i == 0) {
				wtf /= i;
			}
			primes2.push_back(i);
		}
	}
	if(wtf > 1) {
		primes2.push_back(wtf);
	}
	for(long long i = 1; i * i <= m; i++) {
		if(m % i == 0 && i != 1) {
			ans += solve(x, i, primes, primes2);
		}
		if(m % i == 0 && m / i != i) {
			ans += solve(x, mod / i, primes, primes2);
		}
	}
	std::cout << ans << '\n';
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

std::vector<int> primes;
std::set<int> bad;

int getBal(int x) {
	//if(memo.count(x)) return memo[x];
	int ans = 0;
	//std::cout << "solving " << x << std::endl;
	for(auto p : primes) {
		if(p * p > x) {
			break;
		} else if(x % p != 0) {
			continue;
		}
		int e = 0;
		while(x % p == 0) {
			x /= p;
			e++;
		}
		if(bad.count(p)) {
			e = -e;
		}
		ans += e;
	}
	if(x > 1) {
		if(bad.count(x)) {
			ans--;
		} else {
			ans++;
		}
	}
	//std::cout << "got " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i * i <= 1000000000; i++) {
		if(isPrime(i)) {
			primes.push_back(i);
		}
	}
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		int v;
		std::cin >> v;
		bad.insert(v);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += getBal(a[i]);
	}
	for(int i = 1; i < n; i++) {
		a[i] = gcd(a[i], a[i-1]);
	}
	a.push_back(0);
	int best = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] != a[i+1]) {
			best = std::max(best, -getBal(a[i]));
		}
		ans += best;
	}
	std::cout << ans << std::endl;
}
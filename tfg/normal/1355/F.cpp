#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long curAns = -1;

int qry(long long x) {
	std::cout << "? " << x << std::endl;
	if(curAns != -1) {
		return (int) gcd(x, curAns);
	}
	std::cin >> x;
	return (int) x;
}

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

const long long INF = 1e18;
struct Query {
	std::vector<int> wtf;
	Query() {}
	Query(int x) { assert(push_back(x)); }
	long long cur = INF;
	bool push_back(int x) {
		if(x > cur) return false;
		else {
			wtf.push_back(x);
			cur /= x;
			return true;
		}
	}

	bool operator < (const Query &o) const {
		return cur < o.cur;
	}
};

long long getBest(int p, int lim) {
	long long x = 1;
	while(p * x <= lim) {
		x *= p;
	}
	return (int) x;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> primes;
	std::vector<Query> queries;
	for(int i = 2; i <= 730; i++) {
		if(isPrime(i)) {
			primes.push_back(i);
		}
	}
	std::reverse(primes.begin(), primes.end());
	//std::shuffle(primes.begin(), primes.end(), rng);
	for(auto p : primes) {
		for(int i = 0; i <= (int) queries.size(); i++) {
			if(i == (int) queries.size()) {
				queries.emplace_back(p);
				//std::sort(queries.begin(), queries.end());
				break;
			} else if(queries[i].push_back(p)) {
				//std::sort(queries.begin(), queries.end());
				break;
			}
		}
	}
	for(int i = 0; i < (int) queries.size(); i++) {
		//break;
		std::cerr << i+1 << ":";
		for(auto x : queries[i].wtf) std::cerr << ' ' << x;
		std::cerr << '\n';
	}
	int t;
	std::cin >> t;
	while(t--) {
		primes.clear();
		//std::cin >> curAns;
		for(int i = 0; i < (int) queries.size(); i++) {
			long long cur = 1;
			for(auto x : queries[i].wtf) {
				cur *= x;
			}
			cur = qry(cur);
			for(auto x : queries[i].wtf) {
				if(cur % x == 0) {
					primes.push_back(x);
				}
			}
		}
		int ans = 1;
		const int LIM = 1e9;
		while((int) primes.size() > 1) {
			int a = primes.back();
			primes.pop_back();
			int b = primes.back();
			primes.pop_back();
			//std::cerr << "testing for " << a << " and " << b << std::endl;
			int x = qry(getBest(a, LIM) * getBest(b, LIM));
			int e = 0;
			while(x % a == 0) {
				x /= a;
				e++;
			}
			ans *= e + 1;
			e = 0;
			while(x % b == 0) {
				x /= b;
				e++;
			}
			ans *= e + 1;
		}
		if(!primes.empty()) {
			int a = primes.back();
			primes.pop_back();
			//std::cerr << "testing for " << a << std::endl;
			int x = qry(getBest(a, LIM));
			int e = 0;
			while(x % a == 0) {
				x /= a;
				e++;
			}
			ans *= e + 1;
		}
		std::cout << "! " << std::max(ans * 2, ans + 7) << std::endl;
	}
}
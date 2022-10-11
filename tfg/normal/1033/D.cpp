#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//const int ms = 2e6;
const long long MOD = 998244353;

//bool np[ms];

long long fexp(long long x, int e) {
	long long ans = x;
	for(int i = 1; i < e; i++) {
		ans *= x;
	}
	return ans;
}

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b) ; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	/*for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		for(int j = i + i; j < ms; j++) {
			np[j] = true;
		}
	}*/
	int n;
	std::cin >> n;
	std::map<long long, int> freq;
	std::vector<long long> rest;
	while(n--) {
		long long val;
		std::cin >> val;
		//std::cout << "reading " << val << "\n";
		for(int p = 4; p >= 2; p--) {
			long long cand = pow(val, 1.0 / p) - 3;
			cand = std::max(cand, 1LL);
			//std::cout << "got " << cand << ", " << fexp(cand, p) << " for " << p << "\n";
			
			while(fexp(cand, p) < val) cand++;
			//std::cout << "got " << cand << ", " << fexp(cand, p) << " for " << p << "\n";
			if(fexp(cand, p) == val) {
				val = 1;
				freq[cand] += p;
				break;
			}
		}
		if(val == 1) continue;
		int id = -1;
		for(int i = 0; i < (int) rest.size() && id == -1; i++) {
			long long g = gcd(rest[i], val);
			if(g != 1 && g != val) {
				id = i;
			}
		}
		//std::cout << "for " << val << ", id is " << id << std::endl;
		if(id == -1) {
			rest.push_back(val);
		} else {
			//std::cout << "match with " << rest[id] << std::endl;
			long long g = gcd(rest[id], val);
			freq[g] += 2;
			freq[val / g]++;
			freq[rest[id] / g]++;
			std::swap(rest[id], rest.back());
			rest.pop_back();
		}
	}
	std::vector<long long> wtf;
	for(auto v : freq) {
		for(int i = 0; i < (int) rest.size(); i++) {
			if(rest[i] % v.first == 0) {
				wtf.push_back(rest[i] / v.first);
				wtf.push_back(v.first);
				std::swap(rest[i], rest.back());
				rest.pop_back();
				i--;
			}
		}
	}
	for(auto v : wtf) {
		freq[v]++;
	}
	long long ans = 1;
	for(auto v : freq) {
		ans = ans * (v.second + 1) % MOD;
	}
	std::map<long long, int> ops;
	for(auto v : rest) {
		ops[v]++;
	}
	for(auto v : ops) {
		ans = ans * (v.second + 1) % MOD;
		ans = ans * (v.second + 1) % MOD;
	}
	std::cout << ans << std::endl;
}
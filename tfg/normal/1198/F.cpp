#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> primes;

bool isPrime(int x) {
	if(x < 2) return false;
	for(auto p : primes) {
		if(p * p > x) break;
		if(x % p == 0) return false;
	}
	return true;
}

std::vector<int> fact(int x) {
	std::vector<int> ans;
	for(auto p : primes) {
		if(p * p > x) break;
		if(x % p == 0) {
			ans.push_back(p);
			while(x % p == 0) {
				x /= p;
			}
		}
	}
	if(x > 1) {
		ans.push_back(x);
	}
	return ans;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int q[18][1 << 18], qs[18];
bool dp[1 << 18];
int from[1 << 18], used[1 << 18];

int getMask(std::vector<int> &f, int x, int off) {
	int ans = 0;
	for(int i = 0; i < f.size(); i++) {
		if(x % f[i] != 0) {
			ans |= 1 << i;
		}
	}
	return ans << off;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(isPrime(i)) {
			primes.push_back(i);
		}
	}
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int j = 1; j < n && j < 12; j++) {
		std::vector<int> f1 = fact(a[0]), f2 = fact(a[j]);
		// init
		int m = f1.size() + f2.size();
		//std::cout << "f1 is:"; for(auto v : f1) std::cout << ' ' << v; std::cout << std::endl;
		//std::cout << "f2 is:"; for(auto v : f2) std::cout << ' ' << v; std::cout << std::endl;
		assert(m <= 18);
		for(int i = 0; i < (1 << m); i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for(int i = 0; i < m; i++) {
			q[i][0] = 0;
			qs[i] = 1;
		}
		// do dp
		auto makeTrans = [&](int mask, int id) {
			std::vector<int> wtf;
			for(int i = 0; i < m; i++) {
				if(mask & (1 << i)) {
				} else {
					continue;
				}
				int oth = 0;
				for(int j = 0; j < qs[i]; j++) {
					if(q[i][j] != 0 && used[q[i][j]] / 2 == id / 2) {
						std::swap(q[i][j], q[i][oth++]);
						continue;
					}
					int to = q[i][j] | mask;
					//std::cout << "from " << q[i][j] << " to " << to << '\n';
					if(!dp[to]) {
						dp[to] = true;
						from[to] = q[i][j];
						used[to] = id;
						wtf.push_back(to);
					}
				}
				qs[i] = oth;
			}
			for(auto x : wtf) {
				for(int i = 0; i < m; i++) {
					if(x & (1 << i)) {
						continue;
					}
					q[i][qs[i]++] = x;
				}
			}
		};
		for(int i = j+1; i < n; i++) {
			int t1 = getMask(f1, a[i], 0);
			int t2 = getMask(f2, a[i], f1.size());
			//std::cout << "got masks " << t1 << " and " << t2 << '\n';
			makeTrans(t1, 2 * i);
			makeTrans(t2, 2 * i + 1);
		}
		// get answer
		if(dp[(1 << m) - 1]) {
			std::vector<int> ans(n, 1);
			ans[j] = 2;
			for(int i = (1 << m) - 1; i > 0; i = from[i]) {
				ans[used[i] / 2] = used[i] % 2 + 1;
			}
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
			}
			return 0;
		}
		// if not answer, make gcd
		a[0] = gcd(a[0], a[j]);
	}
	std::cout << "NO\n";
}
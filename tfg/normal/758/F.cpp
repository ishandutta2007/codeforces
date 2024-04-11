#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::map<int, std::vector<int>> memo;

int getRep(int x) {
	int ans = 1;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			ans *= i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) ans *= x;
	return ans;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

long long solve(long long vals, int rep) {
	if(!memo.count(rep)) {
		std::vector<int> a;
		a.push_back(0);
		for(int i = 1; i <= rep; i++) {
			a.push_back(a.back());
			if(gcd(i, rep) == 1) {
				a.back()++;
			}
		}
		memo[rep] = a;
	}
	std::vector<int> &a = memo[rep];
	return vals / rep * a.back() + a[(int)(vals % rep)];
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, l, r;
	std::cin >> n >> l >> r;
	if(n > 30) {
		std::cout << "0\n";
	} else if(n == 1) {
		std::cout << r - l + 1 << '\n';
	} else if(n == 2) {
		std::cout << (long long) (r - l) * (r - l + 1) << '\n';
	} else {
		long long ans = 0;
		for(int i = 1; 1; i++) {
			long long mn = 1;
			long long mx = 1;
			for(int j = 1; j < n; j++) {
				mn *= i;
				mx *= i + 1;
			}
			if(mx > r) {
				break;
			}
			int rep = getRep(i);
			long long cur = 0;
			//std::cout << "on " << i << ", mn is " << mn << ", mx is " << mx << ", rep is " << rep << "\n";
			for(int j = 1; 1; j++) {
				if(mn * j < l) continue;
				if(mx * j > r) break;
				// look for how many things in here
				// a1 = mn * j
				// ratio = something / i
				// an = something^n * j
				// something = (an / j)^(1/n)
				long long point = (long long) (pow((double) r / j, 1.0 / n) - 2);
				point = std::max(i + 1LL, point);
				while(1) {
					long long x = 1;
					for(int k = 1; k < n; k++) {
						x *= point + 1;
					}
					if(x * j > r) break;
					point++;
				}
				//std::cout << "for j " << j << ", starting point is " << point << '\n';
				//std::cout << "got " << solve(point - i, rep) << '\n';
				cur += solve(point - i, rep);
			}
			ans += cur;
		}
		std::cout << ans * 2 << '\n';
	}
}
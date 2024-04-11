#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const int ms = 55;

long long dp[ms], fat[ms];
long long safeMul(long long a, long long b) {
	if(INF / a / b == 0) return INF;
	else return a * b;
}

int par[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) { par[getPar(a)] = par[getPar(b)]; }
void prep(int n) {
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
}

std::vector<int> solve(int n, long long k) {
	assert(k <= dp[n]);
	std::vector<int> ans;
	ans.push_back(n-1);
	std::vector<int> a;
	for(int i = 0; i+1 < n; i++) {
		a.push_back(i);
	}
	prep(n);
	int j = 0;
	while((int) ans.size() < n) {
		int i = 0;
		j++;
		while(getPar(a[i]) == getPar(j)) i++;
		assert(n-j-1 == (int) a.size() - 1);
		int size = std::max(n-j-2, 0);
		while(k > fat[size]) {
			i++;
			k -= fat[size];
			while(getPar(a[i]) == getPar(j)) i++;
		}
		assert(i < n);
		ans.push_back(a[i]);
		makeUnion(a[i], j);
		a.erase(a.begin() + i);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = safeMul(fat[i-1], i);
	}
	dp[0] = dp[1] = 1;
	for(int i = 2; i < ms; i++) {
		dp[i] = dp[i-1];
		for(int j = 2; j <= i; j++) {
			//std::cout << "dp[" << i <<  "] += " << fat[j-2] << "*" << dp[i-j] << "\n";
			dp[i] = std::min(INF, dp[i] + safeMul(fat[j-2], dp[i-j]));
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		long long k;
		std::cin >> n >> k;
		//std::cout << "(" << k << ", " << dp[n] << ") for " << n << "\n";
		if(dp[n] < k) {
			std::cout << "-1\n";
			continue;
		}
		std::vector<int> ans;
		for(int l = 0, r = 0; l < n; l = r) {
			if(dp[n - l - 1] >= k) {
				ans.push_back(l+1);
				r++;
				//std::cout << "got range [" << l << ", " << r << ")" << std::endl;
				continue;
			}
			k -= dp[n - l - 1];
			r++;
			while(safeMul(fat[r-l-1], dp[n-r-1]) < k) {
				k -= safeMul(fat[r-l-1], dp[n-r-1]);
				r++;
				assert(r < n);
			}
			assert(r < n);
			r++;
			long long kk = (k-1) / dp[n-r] + 1;
			auto got = solve(r - l, kk);
			k = (k-1) % dp[n-r] + 1;
			for(auto v : got) {
				ans.push_back(v + l + 1);
			}
			//std::cout << "got range [" << l << ", " << r << ")" << std::endl;
		}
		for(int i = 0; i < n; i++) {
			std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
		}
	}
}
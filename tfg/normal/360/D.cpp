#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;

int MOD;

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

std::vector<int> divs(int n) {
	std::vector<int> ans;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			ans.push_back(i);
			if(n / i != i) {
				ans.push_back(n / i);
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}

int gcd(int a, int b) {
	if(!b) return a;
	else return gcd(b, a % b);
}

int main() {
	int n, m;
	std::cin >> n >> m >> MOD;
	std::vector<int> d = divs(MOD - 1);
	std::vector<bool> flag(d.size(), false);
	std::vector<int> freq(d.size(), 0);
	std::set<int> steps;
	std::set<int> gots;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		int idx = 0;
		while(fexp(t, d[idx]) != 1) idx++;
		//std::cout << t << " has step size " << (MOD - 1) / d[idx] << std::endl;
		gots.insert((MOD - 1) / d[idx]);
	}
	for(int i = 0; i < m; i++) {
		int t;
		std::cin >> t;
		t %= MOD - 1;
		t = gcd(t, MOD - 1);
		if(t != 0) {
			//std::cout << "got a with step size " << t << std::endl;
			steps.insert(t);
		}
	}
	
	for(auto t : gots) {
		//std::cout << "testing for " << t << std::endl;
		int g = 0;
		for(auto v : steps) {
			int cur = gcd((ll) v * t % (MOD - 1), MOD - 1);
			g = gcd(g, cur);
		}
		if(g == 0) continue;
		//std::cout << "got step size " << g << std::endl;
		flag[std::lower_bound(d.begin(), d.end(), g) - d.begin()] = true;
	}
	flag.back() = true;
	int ans = 0;
	for(int i = (int)freq.size() - 1; i >= 0; i--) {
		freq[i] = (MOD - 1) / d[i];
		for(int j = i + 1; j < freq.size(); j++) {
			if(d[j] % d[i] == 0) {
				freq[i] -= freq[j];
			}
		}
	}
	for(int i = 0; i < freq.size(); i++) {
		if(flag[i]) {
			for(int j = i + 1; j < freq.size(); j++) {
				if(d[j] % d[i] == 0) {
					flag[j] = true;
				}
			}
			ans += freq[i];
		}
	}
	std::cout << ans << std::endl;
}
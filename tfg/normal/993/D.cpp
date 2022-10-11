#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct Info {
	ll power, process;
	
	bool operator <(Info o) const { return (power != o.power ? power > o.power : process > o.process); } 
};

std::vector<Info> v;

bool can(long long x) {
	int n = v.size();
	std::vector<long long> cost(n);
	for(int i = 0; i < n; i++) {
		cost[i] = v[i].power * 1000 - x * v[i].process;
	}
	std::vector<long long> dp(n + 1, 1e18);
	dp[0] = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && v[l].power == v[r].power) r++;
		std::vector<long long> trans(r - l + 1, 0);
		//std::sort(cost.begin() + l, cost.begin() + r);
		for(int i = 0; l + i < r; i++) {
			trans[i + 1] = trans[i] + cost[l + i];
		}
		std::vector<long long> nxt(n + 1, 1e18);
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= r - l; j++) {
				int idx = i - (r - l - j) + j;
				
				if(idx <= n && r - l - j <= i && idx >= 0) {
					//std::cout << idx << ": on group " << r - l << ", using " << r - l - j << " resting " << j << " from " << i << std::endl;
					nxt[idx] = std::min(nxt[idx], dp[i] + trans[j]);
				} else {
					//std::cout << idx << "no: on group " << r - l << ", using " << r - l - j << " resting " << j << " from " << i << std::endl;
				}
			}
		}
		for(int i = n - 1; i >= 0; i--) {
			nxt[i] = std::min(nxt[i], nxt[i + 1]);
		}
		for(int i = 0; i <= n; i++) {
			//std::cout << nxt[i] << (i == n ? '\n' : ' ');
		}
		std::swap(nxt, dp);
	}
	//std::cout << "for " << x << ", got " << dp[0] << "\n";
	return dp[0] <= 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		std::cin >> v[i].power;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> v[i].process;
	}
	std::sort(v.begin(), v.end());
	/*long long ans = 1e18;
	for(int i = n / 2; i < n; i++) {
		long long num = 0;
		long long den = 0;
		for(int j = 0; j <= i; j++) {
			num += v[j].power;
			den += v[j].process;
		}
		long long cur_ans = (num * 1000 + den - 1) / den;
		for(int j = 0; j <= i; j++) {
			for(int k = 0; 
		}
	}*/
	
	long long l = 0, r = 1e15;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(can(mid)) {
			//std::cout << "1\n";
			r = mid;
		} else {
		
			//std::cout << "2\n";
			l = mid + 1;
		}
	}
	std::cout << l << std::endl;
}
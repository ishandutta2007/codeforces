#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int findCycle(int x, int a, int b, int p) {
	int ans = 0;
	int cur = x;
	while(ans == 0 || cur != x) {
		if(ans > 2 * p) {
			return -1;
		}
		cur = (cur * a + b) % p;
		ans++;
	}
	return ans;
}

const int ms = 2002000;
const int MOD = (int) 1e9 + 7;

int pri[ms];
int freq[ms];
int ans[ms], mx_freq[ms];

bool solve(int x) {
	//std::cout << "solving for " << x << std::endl;
	bool valid = false;
	while(x > 1) {
		int e = 0;
		int p = pri[x];
		while(x % p == 0) {
			x /= p;
			e++;
		}
		if(ans[p] < e) {
			valid = true;
			ans[p] = e;
			mx_freq[p] = 0;
		}
		if(ans[p] == e) {
			mx_freq[p]++;
		}
	}
	return valid;
}

bool eval(int x) {
	bool valid = true;
	while(x > 1) {
		int e = 0;
		int p = pri[x];
		while(x % p == 0) {
			x /= p;
			e++;
		}
		if(ans[p] == e && mx_freq[p] == 1) {
			valid = false;
		}
	}
	return valid;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	/*int p;
	std::cin >> p;
	std::set<int> nums;
	for(int x = 0; x < p; x++) {
		for(int a = 1; a < p; a++) {
			for(int b = 0; b < p; b++) {
				//std::cout << "(" << x << ", " << a << ", " << b << ") has cycle of length " << findCycle(x, a, b, p) << std::endl;
				nums.insert(findCycle(x, a, b, p));
			}
		}
	}
	for(auto v : nums) {
		std::cout << v << std::endl;
	}*/
	int n;
	std::cin >> n;
	for(int i = 2; i < ms; i++) {
		if(pri[i]) {
			continue;
		}
		for(int j = i; j < ms; j += i) {
			pri[j] = i;
		}
	}
	for(int i = 0; i < n; i++) {
		int p;
		//std::cin >> p;
		scanf("%d", &p);
		freq[p]++;
	}
	bool flag = false;
	std::vector<int> wtf;
	for(int i = ms - 1; i > 0; i--) {
		if(freq[i] > 0 && !ans[i]) {
			solve(i);
			freq[i]--;
		}
		if(freq[i] > 0 && solve(i-1)) {
			freq[i]--;
			wtf.push_back(i-1);
		}
		if(freq[i] > 0) {
			flag = true;
		}
	}
	for(auto i : wtf) {
		flag = flag || eval(i);
	}
	long long tot = 1;
	for(int i = 1; i < ms; i++) {
		while(ans[i]--) {
			tot = tot * i % MOD;
		}
	}
	if(flag) {
		tot = (tot + 1) % MOD;
	}
	std::cout << tot << std::endl;
}
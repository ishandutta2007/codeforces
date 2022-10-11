#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

std::vector<int> ans;
int f[ms];

void solve(std::vector<int> nums, int m = 1) {
	if(nums.size() == 1) {
		ans.push_back(m);
		return;
	}
	int mx = 0;
	for(auto v : nums) {
		mx = std::max(mx, v);
	}
	for(int i = 0; i <= mx; i++) {
		f[i] = 0;
	}
	for(auto v : nums) {
		f[v]++;
	}
	for(int i = 1; i <= mx; i++) {
		for(int j = i + i; j <= mx; j += i) {
			f[i] += f[j];
		}
	}
	int want = 0;
	for(int i = mx; i >= 2; i--) {
		if(f[i] > f[want]) {
			want = i;
		}
	}
	std::vector<int> nxt;
	for(auto v : nums) {
		if(v % want != 0) {
			ans.push_back(m);
		} else {
			nxt.push_back(v / want);
		}
	}
	//std::cout << "had:";for(auto v : nums) std::cout << ' ' << v; std::cout << std::endl;
	//std::cout << "want is " << want << "\n";
	//std::cout << "got:";for(auto v : nxt) std::cout << ' ' << v; std::cout << std::endl;
	nums.clear();
	solve(nxt, m * want);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> hmm(n);
	for(int i = 0; i < n; i++) {
		hmm[i] = i + 1;
	}
	solve(hmm, 1);
	for(int i = 0; i < n; i++) {
		printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
	}
}
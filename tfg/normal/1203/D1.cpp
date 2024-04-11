#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t;
	std::cin >> s >> t;
	int n = (int) s.size(), m = (int) t.size();
	std::vector<int> ans(m+1, 0);
	int mx = 0;
	{
		// indo
		int st = 0;
		for(int i = 0; i < n && st < m; i++) {
			if(t[st] == s[i]) {
				ans[++st] += -i;
			}
			if(st == m) {
				mx = std::max(mx, n-i-1);
			}
		}
		// voltando
		st = m-1;
		for(int i = n-1; i >= 0 && st >= 0; i--) {
			if(t[st] == s[i]) {
				ans[st--] += i - 1;
			}
			if(st == -1) {
				mx = std::max(mx, i);
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		mx = std::max(mx, ans[i]);
	}
	std::cout << mx << '\n';
}
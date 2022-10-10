#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solve(const std::vector<int> &a, const std::vector<int> &b) {
	int ans = 0;
	int got = 0;
	for(int i = 0, j = 0; i != (int) a.size() || j != (int) b.size();) {
		if(j == (int) b.size() || (i != (int) a.size() && a[i] < b[j])) {
			if(got != 1) {
				ans++;
				got = 1;
			}
			i++;
		} else {
			if(got != 2) {
				ans++;
				got = 2;
			}
			j++;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::map<int, std::vector<int>> wtf;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		wtf[x].push_back(i);
	}
	int ans = 0;
	for(auto it = wtf.begin(); it != wtf.end(); it++) {
		auto it2 = it;
		for(it2++; it2 != wtf.end(); it2++) {
			ans = std::max(ans, solve(it->second, it2->second));
		}
		ans = std::max(ans, (int) it->second.size());
	}
	std::cout << ans << '\n';
}
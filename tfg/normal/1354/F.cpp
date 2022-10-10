#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Info {
	int first, second;
	int id;

	bool operator < (const Info &o) const {
		if(first != o.first) return first < o.first;
		else return second < o.second;
	}
};

int n, k;
Info a[80];
int memo[80][80];
int dp(int on, int used) {
	if(used > k) return -1e9;
	int &ans = memo[on][used];
	if(ans != -1) return ans;
	if(on == n) {
		return ans = used == k ? 0 : int(-1e9);
	} else {
		return ans = std::max(dp(on+1, used) + (k-1) * a[on].first, dp(on+1, used+1) + a[on].second + used * a[on].first);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i].second >> a[i].first;
			a[i].second = -a[i].second;
			a[i].id = i+1;
		}
		std::sort(a, a + n);
		for(int i = 0; i < n; i++) {
			a[i].second = -a[i].second;
		}
		std::cerr << dp(0, 0) << '\n';
		std::vector<int> bas;
		std::vector<bool> got(n+1, false);
		for(int i = 0, j = 0; i < n; ) {
			if(dp(i, j) == dp(i+1, j) + (k-1) * a[i].first) {
				i++;
			} else {
				bas.push_back(a[i].id);
				got[a[i].id] = true;
				i++;
				j++;
			}
		}
		std::vector<int> ans;
		assert((int) bas.size() == k);
		for(int i = 0; i+1 < k; i++) {
			ans.push_back(bas[i]);
		}
		for(int i = 1; i <= n; i++) {
			if(!got[i]) {
				ans.push_back(i);
				ans.push_back(-i);
			}
		}
		ans.push_back(bas.back());
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}
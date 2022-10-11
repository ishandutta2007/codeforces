#include <iostream>
#include <vector>
#include <map>

typedef long long ll;
typedef std::pair<ll, int> ii;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::map<int, int> freq;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		freq[t]++;
	}
	std::vector<int> pt(n + 1, n);
	std::vector<ii> nums;
	for(auto a : freq) {
		nums.emplace_back(a.first, a.second);
	}
	nums.emplace_back(2e9, 0);
	int ans[] = {0, n, n, n};
	for(int e = 0; e < 33; e++) {
		ll diff = 1LL << e;
		for(int l = 0, r = 0; l < n; l++) {
			while(r < n && nums[r].first < nums[l].first + diff) {
				r++;
			}
			pt[l] = (nums[r].first == nums[l].first + diff ? r : n);
		}
		for(int i = 0; i < n; i++) {
			int got = nums[i].second + nums[pt[i]].second + nums[pt[pt[i]]].second;
			if(got > ans[0]) {
				ans[0] = got;
				ans[1] = i;
				ans[2] = pt[ans[1]];
				ans[3] = pt[ans[2]];
			}
		}
	}
	std::cout << ans[0] << std::endl;
	//std::cout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << std::endl;
	std::vector<int> vals;
	for(int i = 1; i < 4; i++) {
		while(nums[ans[i]].second > 0) {
			vals.push_back(nums[ans[i]].first);
			nums[ans[i]].second--;
		}
	}
	for(int i = 0; i < vals.size(); i++) {
		std::cout << vals[i] << (i + 1 == vals.size() ? '\n' : ' ');
	}
}
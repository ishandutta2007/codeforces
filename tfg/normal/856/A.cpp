#include <iostream>
#include <vector>
#include <algorithm>

const int ms = 1e6 + 1e5;

int step = 0;
int cur_step[ms];

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a;
		for(int i = 0; i < n; i++) {
			int temp;
			std::cin >> temp;
			a.push_back(temp);
		}
		std::sort(a.begin(), a.end());
		step++;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				cur_step[a[j] - a[i]] = step;
			}
		}
		std::vector<int> ans;
		for(int i = 1; ans.size() < n && i <= 1e6; i++) {
			bool can = true;
			for(int j = 0; j < ans.size() && can; j++) {
				can = can && cur_step[i - ans[j]] != step;
			}
			if(can) {
				ans.push_back(i);
			}
		}
		if(ans.size() == n) {
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
			}
		} else {
			std::cout << "NO\n";
		}
	}
}
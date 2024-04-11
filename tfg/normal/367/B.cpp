#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

std::map<int, int> want;
int n, m, p;

std::vector<int> solve(std::vector<int> arr) {
	std::map<int, int> freq;
	std::vector<int> ans;
	for(int l = 0, r = 0; l < arr.size(); l++) {
		if(l > r) {
			freq.clear();
			r = l;
		}
		while(r < arr.size() && want.count(arr[r]) && want[arr[r]] > freq[arr[r]]) {
			freq[arr[r++]]++;
		}
		if(r - l == m) {
			ans.push_back(l);
		}
		freq[arr[l]]--;
		//std::cout << "(" << l << ", " << r << ")\n";
	}
	return ans;
}

int main() {
	std::cin >> n >> m >> p;
	std::vector<int> ori;
	for(int i = 0; i < n; i++) {
		int t;
		//std::cin >> t;
		scanf("%i", &t);
		ori.push_back(t);
	}
	for(int i = 0; i < m; i++) {
		int t;
		//std::cin >> t;
		scanf("%i", &t);
		want[t]++;
	}
	std::vector<int> ans;
	for(int i = 0; i < p; i++) {
		std::vector<int> cur;
		for(int j = 0; i + j * p < n; j++) {
			cur.push_back(ori[i + j * p]);
		}
		cur = solve(cur);
		for(auto a : cur) {
			ans.push_back(i + a * p + 1);
		}
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}
#include <iostream>
#include <vector>

const int ms = 100100;

std::vector<int> pos[ms];
int got[ms];
int sum[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		a = std::max(a, -a);
		got[i]++;
		pos[a].push_back(i);
	}
	long long ans = 0;
	for(int i = ms - 1; i > 0; i--) {
		if(pos[i].size() == 0) {
			continue;
		}
		for(auto p : pos[i]) {
			got[p]--;
		}
		for(int j = 1; j <= n; j++) {
			sum[j] = sum[j - 1] + got[j];
		}
		std::vector<int> costs;
		long long cur_ans = 0;
		for(auto p : pos[i]) {
			int cur_cost = sum[n] - sum[p];
			cur_cost -= sum[p];
			costs.push_back(cur_cost);
			cur_ans += sum[p];
			//std::cout << "for position " << p << " got cost " << cur_cost << '\n';
		}
		//std::cout << "tot cost for " << i << " is " << cur_ans << '\n';
		long long best = cur_ans;
		for(int i = 0; i < costs.size(); i++) {
			cur_ans += costs[costs.size() - i - 1];
			best = std::min(best, cur_ans);
		}
		ans += best;
		//std::cout << "best is " << best << '\n';
	}
	std::cout << ans << '\n';
}
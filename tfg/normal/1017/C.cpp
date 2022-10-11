#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> brute(int n) {
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i + 1;
	}
	int mn = 1289739;
	std::vector<int> ans;
	do {
		std::vector<int> lis;
		std::vector<int> lds;
		for(auto v : p) {
			int idx = std::lower_bound(lis.begin(), lis.end(), v) - lis.begin();
			if(idx == lis.size()) lis.push_back(-1);
			lis[idx] = v;
			idx = std::lower_bound(lds.begin(), lds.end(), -v) - lds.begin();
			if(idx == lds.size()) lds.push_back(-1);
			lds[idx] = -v;
			//std::cout << v << ' ';
		}
		if(lis.size() + lds.size() < mn) {
			ans = p;
		}
		mn = std::min(mn, (int) (lis.size() + lds.size()));
		//std::cout << " got (" << lis.size() << ", " << lds.size() << ") = " << lis.size() + lds.size() << " and mn = " << mn << "\n";
	} while(std::next_permutation(p.begin(), p.end()));
	return ans;
}

std::vector<int> greedy(int n) {
	int size = 1;
	int cost = n + 1;
	for(int i = 2; i <= n; i++) {
		int cur_cost = i + (n + i - 1) / i;
		//std::cout << "cost for " << i << " is " << cur_cost << std::endl;
		if(cur_cost < cost) {
			cost = cur_cost;
			size = i;
		}
	}
	std::vector<int> ans(n);
	for(int j = 1; j <= n; j += size) {
		if(j + size > n) {
			for(int i = 0; i + j - 1 < n; i++) {
				ans[i + j - 1] = n - i;
			}
		} else {
			for(int i = 0; i < size; i++) {
				ans[i + j - 1] = j + size - 1 - i;
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> ans;
	if(n < 7) {
		ans = brute(n);
	} else {
		ans = greedy(n);
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}
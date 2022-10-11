#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

typedef std::pair<int, int> ii;

const int ms = 100100;

bool np[ms];
int use[ms];
int p[ms], a[ms];
int dp[ms];

int main() {
	for(int i = 2; i < ms; i++) {
		use[i] = use[i - 1];
		if(np[i]) {
			continue;
		}
		use[i] = i;
		for(int j = i + i; j < ms; j += i) {
			np[j] = true;
		}
	}
	int mx = 0;
	for(int i = 2; i < ms; i++) {
		//std::cout << "from " << i << ", to " << i - use[i] << "\n";
		dp[i] = dp[i - use[i]] + 1;
		mx = std::max(mx, dp[i]);
	}
	//std::cout << "mx is " << mx << "\n";
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		p[a[i]] = i;
	}
	std::vector<ii> ans;
	for(int i = 1; i <= n; i++) {
		while(p[i] != i) {
			//std::cout << "trying to fix " << i << ", is on " << p[i] << "\n";
			int jmp = use[p[i] - i + 1];
			int other = p[i] - jmp + 1;
			//std::cout << "other is " << other << "\n";
			ans.emplace_back(other, p[i]);
			std::swap(a[p[i]], a[other]);
			std::swap(p[i], p[a[p[i]]]);
		}
	}
	std::cout << ans.size() << '\n';
	for(auto jmp : ans) {
		printf("%d %d\n", jmp.first, jmp.second);
	}
}
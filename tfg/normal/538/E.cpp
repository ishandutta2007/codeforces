#include <iostream>
#include <vector>

const int ms = 200200;

std::vector<int> edges[ms];
int size[ms];

int pre(int on, int par = -1) {
	for(auto to : edges[on]) {
		if(to != par) {
			pre(to, on);
			size[on] += size[to];
		}
	}
	if(size[on] == 0) {
		size[on]++;
	}
}

int solve(int on, int par = -1, bool max = true) {
	if(edges[on].size() == 0) {
		return 0;
	}
	int ans = 0;
	//std::cout << "on (" << on << ", " << max << ")\n";
	for(auto to : edges[on]) {
		if(to != par) {
			int cur = solve(to, on, !max);
			if(max) {
				ans = std::max(ans, size[on] - size[to] + cur);
			} else {
				ans += cur;
			}
		}
	}
	//std::cout << "on (" << on << ", " << max << ") got " << ans << "\n";
	return ans;
}

int main() {
	int n;
	std::cin >> n;
	edges[0].push_back(1);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
	}
	pre(0);
	std::cout << solve(1) + 1 << ' ' << (size[0] - solve(0)) << '\n';
}
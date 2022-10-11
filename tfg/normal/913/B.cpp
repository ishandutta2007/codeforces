#include <iostream>
#include <vector>

std::vector<int> edges[1010];

bool dfs(int on) {
	if(edges[on].size() == 0) {
		return true;
	}
	int leaf = 0;
	bool ans = true;
	for(auto a : edges[on]) {
		if(edges[a].size() == 0) {
			leaf++;
		} else {
			ans = ans && dfs(a);
		}
	}
	return ans && leaf >= 3;
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p - 1].push_back(i);
	}
	if(dfs(0)) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}
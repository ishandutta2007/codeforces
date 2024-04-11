#include <iostream>
#include <vector>

const int ms = 100100;

std::vector<int> edges[ms];
int freq[ms];

void dfs(int on, int h = 0) {
	freq[h]++;
	for(auto to : edges[on]) {
		dfs(to, h + 1);
	}
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int to;
		std::cin >> to;
		to--;
		edges[to].push_back(i);
	}
	dfs(0);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += freq[i] & 1;
	}
	std::cout << ans << '\n';
}
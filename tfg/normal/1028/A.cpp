#include <iostream>
#include <vector>
#include <utility>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<std::pair<int, int>> pos;
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for(int j = 0; j < m; j++) {
			if(str[j] == 'B') {
				pos.emplace_back(i + 1, j + 1);
			}
		}
	}
	int i = pos.size() / 2;
	std::cout << pos[i].first << ' ' << pos[i].second << std::endl;
}
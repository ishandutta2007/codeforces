#include <iostream>
#include <vector>

const int ms = 2020;

std::vector<int> pos[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		pos[t].push_back(i + 1);
	}
	std::vector<int> ans[3];
	for(int i = 0, got = 0; i < ms; i++) {
		if(pos[i].size() == 1) {
			for(int j = 0; j < 3; j++) {
				ans[j].push_back(pos[i].back());
			}
		} else if(pos[i].size() > 1) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < pos[i].size(); k++) {
					ans[(j + got) % 3].push_back(pos[i][(j + k) % pos[i].size()]);
				}
			}
			got++;
		}
	}
	if(ans[0] == ans[1] || ans[1] == ans[2] || ans[0] == ans[2]) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		for(int j = 0; j < 3; j++) {
			for(int i = 0; i < n; i++) {
				std::cout << ans[j][i] << (i + 1 == n ? '\n' : ' ');
			}
		}
	}
}
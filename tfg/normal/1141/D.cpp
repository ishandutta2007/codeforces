#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> pos[2][27];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int> > ans;
	std::string a, b;
	std::cin >> a >> b;
	for(int i = 0; i < n; i++) {
		if(a[i] == '?') {
			pos[0][26].push_back(i);
		} else {
			pos[0][a[i] - 'a'].push_back(i);
		}
		if(b[i] == '?') {
			pos[1][26].push_back(i);
		} else {
			pos[1][b[i] - 'a'].push_back(i);
		}
	}
	for(int i = 0; i < 26; i++) {
		while(pos[0][i].size() && pos[1][i].size()) {
			ans.emplace_back(pos[0][i].back(), pos[1][i].back());
			pos[0][i].pop_back();
			pos[1][i].pop_back();
		}
	}
	for(int i = 0; i < 26; i++) {
		while(pos[0][i].size() && pos[1][26].size()) {
			ans.emplace_back(pos[0][i].back(), pos[1][26].back());
			pos[0][i].pop_back();
			pos[1][26].pop_back();
		}
		while(pos[0][26].size() && pos[1][i].size()) {
			ans.emplace_back(pos[0][26].back(), pos[1][i].back());
			pos[0][26].pop_back();
			pos[1][i].pop_back();
		}
	}
	while(pos[0][26].size() && pos[1][26].size()) {
		ans.emplace_back(pos[0][26].back(), pos[1][26].back());
		pos[0][26].pop_back();
		pos[1][26].pop_back();
	}
	std::cout << ans.size() << '\n';
	for(auto p : ans) {
		std::cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef std::pair<int, int> ii;

int n, m;

std::vector<std::pair<ii, ii>> solve(std::vector<std::vector<std::string>> state, bool wtf = false) {
	if(wtf) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::reverse(state[i][j].begin(), state[i][j].end());
			}
		}
	}
	std::vector<std::pair<ii, ii>> ans;
	state[n-1][0] = state[n-1][m-1] + state[0][0] + state[n-1][0];
	while(state[0][0].size() > 0) {
		state[0][0].pop_back();
		ans.emplace_back(ii(0, 0), ii(n-1, 0));
	}
	while(state[n-1][m-1].size() > 0) {
		state[n-1][m-1].pop_back();
		ans.emplace_back(ii(n-1, m-1), ii(n-1, 0));
	}
	while(state[n-1][0].size() > 0) {
		break;
		int c = state[n-1][0].back() - '0';
		state[n-1][0].pop_back();
		if(c == 0) {
			ans.emplace_back(ii(n-1, 0), ii(0, 0));
		} else {
			ans.emplace_back(ii(n-1, 0), ii(n-1, m-1));
		}
	}
	std::vector<std::vector<int>> pt(n, std::vector<int>(m, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::reverse(state[i][j].begin(), state[i][j].end());
		}
	}
	for(int rep = 0; rep < 2; rep++)
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			while(pt[i][j] < state[i][j].size()) {
				int c = state[i][j][pt[i][j]++] - '0';
				//std::cout << "on pos (" << i << ", " << j << ") got " << c << " on rep " << rep << std::endl;
				if(c == 0) {
					if(i == 0) {
						ans.emplace_back(ii(i, j), ii(0, 0));
					} else {
						ans.emplace_back(ii(i, j), ii(0, j));
						if(j != 0) state[0][j] += '0';
					}
				} else {
					if(i == n-1) {
						ans.emplace_back(ii(i, j), ii(n-1, m-1));
					} else {
						ans.emplace_back(ii(i, j), ii(n-1, j));
						if(j != m - 1) state[n-1][j] += '1';
					}
				}
			}
		}
	}
	return ans;
}

void show(std::vector<std::vector<std::string>> &state) {
	return;
	std::cout << "-------------------------------------------" << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cout << state[i][j] << (j + 1 == m ? '\n' : ' ');
		}
	}
}

void apply(std::vector<std::vector<std::string>> &state, std::pair<ii, ii> lul) {
	return;
	show(state);
	int x1 = lul.first.first, y1 = lul.first.second;
	int x2 = lul.second.first, y2 = lul.second.second;
	//std::cout << "applying (" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")" << std::endl;
	state[x2][y2] = state[x1][y1].back() + state[x2][y2];
	state[x1][y1].pop_back();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	std::vector<std::vector<std::string>> st, en;
	st.assign(n, std::vector<std::string>(m));
	en.assign(n, std::vector<std::string>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> st[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> en[i][j];
		}
	}
	auto s1 = solve(st);
	auto s2 = solve(en, true);
	std::reverse(s2.begin(), s2.end());
	std::cout << s1.size() + s2.size() << '\n';
	for(auto &e : s1) {
		apply(st, e);
		std::cout << e.first.first + 1 << ' ' << e.first.second + 1 << ' ' << e.second.first + 1 << ' ' << e.second.second + 1 << '\n';
	}
	//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!ended\n";
	for(auto &e : s2) {
		std::swap(e.first, e.second);
		apply(st, e);
		std::cout << e.first.first + 1 << ' ' << e.first.second + 1 << ' ' << e.second.first + 1 << ' ' << e.second.second + 1 << '\n';
	}
	show(st);
	show(en);
}
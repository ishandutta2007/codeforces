#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::map<std::string, std::vector<int>> brute;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mat(n);
	std::vector<std::pair<int, int>> ans;
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	auto go = [&](){
		for(int i = 1; i <= 3; i++) {
			auto pt = ans[(int) ans.size() - i];
			mat[pt.first][pt.second] ^= '0' ^ '1';
		}
	};
	auto print = [&](){
		for(int i = 0; i < n; i++) {
			std::cout << mat[i] << std::endl;
		}
	};
	for(int i = n-1; i >= 2; i--) {
		for(int j = m-2; j >= 0; j--) {
			if(mat[i][j] == '1' && mat[i][j+1] == '1') {
				ans.emplace_back(i, j);
				ans.emplace_back(i, j+1);
				ans.emplace_back(i-1, j);
				go();
			} else if(mat[i][j] == '1') {
				ans.emplace_back(i, j);
				ans.emplace_back(i-1, j);
				ans.emplace_back(i-1, j+1);
				go();
			} else if(mat[i][j+1] == '1') {
				ans.emplace_back(i, j+1);
				ans.emplace_back(i-1, j);
				ans.emplace_back(i-1, j+1);
				go();
			}
		}
	}
	//print();
	for(int i = 1; i >= 1; i--) {
		for(int j = m-1; j >= 2; j--) {
			if(mat[i][j] == '1' && mat[i-1][j] == '1') {
				ans.emplace_back(i, j);
				ans.emplace_back(i-1, j);
				ans.emplace_back(i, j-1);
				go();
			} else if(mat[i][j] == '1') {
				ans.emplace_back(i, j);
				ans.emplace_back(i, j-1);
				ans.emplace_back(i-1, j-1);
				go();
			} else if(mat[i-1][j] == '1') {
				ans.emplace_back(i-1, j);
				ans.emplace_back(i-1, j-1);
				ans.emplace_back(i, j-1);
				go();
			}
		}
	}
	//print();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			assert(mat[i][j] == '0' || (i < 2 && j < 2));
		}
	}
	std::string st;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			st += mat[i][j];
		}
	}
	auto other = brute[st];
	for(auto x : other) ans.emplace_back(x / 2, x % 2);
	std::cout << ans.size() / 3 << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << (i % 3 == 2 ? '\n' : ' ');
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// brute preprocessing
	std::queue<std::string> q;
	q.push(std::string(4, '0'));
	brute[std::string(4, '0')] = std::vector<int>(0);
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		auto base_ans = brute[cur];
		for(auto &ch : cur) {
			ch ^= '0' ^ '1';
		}
		assert((int) base_ans.size() % 3 == 0 && (int) base_ans.size() / 3 <= 4);
		for(int i = 0; i < 4; i++) {
			cur[i] ^= '0' ^ '1';
			if(!brute.count(cur)) {
				auto ans = base_ans;
				for(int j = 0; j < 4; j++) {
					if(j != i) {
						ans.push_back(j);
					}
				}
				brute[cur] = ans;
				q.push(cur);
			}
			cur[i] ^= '0' ^ '1';
		}
	}
	assert((int) brute.size() == (1 << 4));
	// brute end
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}
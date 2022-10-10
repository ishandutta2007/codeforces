#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string str;
std::string ans;
int k;

void go(std::vector<int> &pos) {
	if(!pos.empty() && pos.back() == (int) str.size()) pos.pop_back();
	if(pos.empty()) return;
	std::vector<int> cur[26];
	for(auto i : pos) {
		cur[str[i] - 'a'].push_back(i+1);
	}
	pos.clear();
	for(int i = 0; i < 26; i++) {
		int got = (int) cur[i].size();
		ans += char('a' + i);
		if(got >= k) {
			std::cout << ans << '\n';
			exit(0);
		}
		k -= got;
		go(cur[i]);
		ans.pop_back();
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> str;
	std::vector<int> pos;
	for(int i = 0; i < (int) str.size(); i++) {
		pos.push_back(i);
	}
	std::cin >> k;
	go(pos);
	std::cout << "No such line.\n";
}
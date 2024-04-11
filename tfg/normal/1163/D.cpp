#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <cstring>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 55 * 2;

int trie[ms][26], c = 1;
int fail[ms], cost[ms];

int addString(std::string str) {
	int on = 0;
	for(auto cc : str) {
		if(trie[on][cc - 'a'] == 0) {
			trie[on][cc - 'a'] = c++;
		}
		on = trie[on][cc - 'a'];
	}
	return on;
}

void buildAho() {
	std::vector<int> q(1, 0);
	for(int i = 0; i < (int) q.size(); i++) {
		int on = q[i];
		cost[on] += cost[fail[on]];
		std::swap(i, on);
		for(int j = 0; j < 26; j++) {
			if(trie[i][j]) {
				q.push_back(trie[i][j]);
			}
			if(i == 0) {

			} else if(trie[i][j] == 0) {
				trie[i][j] = trie[fail[i]][j];
			} else {
				fail[trie[i][j]] = trie[fail[i]][j];
			}
		}
		std::swap(i, on);
	}
}

std::string str;

int memo[1010][ms];

int dp(int on, int st) {
	int &ans = memo[on][st];
	if(ans != 0x3f3f3f3f) {
		return ans;
	}
	ans = -1e8;
	if(on == (int) str.size()) {
		return ans = 0;
	}
	if(str[on] == '*') {
		for(int i = 0; i < 26; i++) {
			int toSt = trie[st][i];
			ans = std::max(ans, dp(on + 1, toSt) + cost[toSt]);
		}
	} else {
		int toSt = trie[st][str[on] - 'a'];
		ans = std::max(ans, dp(on + 1, toSt) + cost[toSt]);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string pat[2];
	std::cin >> str >> pat[0] >> pat[1];
	cost[addString(pat[0])]++;
	cost[addString(pat[1])]--;
	buildAho();
	memset(memo, 0x3f, sizeof memo);
	std::cout << dp(0, 0) << '\n';
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

int c = 1;
int trie[10][26];
bool bad[10];

void addString(std::string str) {
	int on = 0;
	for(auto ch : str) {
		trie[on][ch - 'a'] = c++;
		on = trie[on][ch - 'a'];
	}
	bad[on] = true;
}

const int ms = 200100;

int curStep = 0, step[ms][10];
int memo[ms][10], to[ms][10];

std::string str;

int dp(int on, int st) {
	if(bad[st]) return -INF;
	if(on == (int) str.size()) return 0;
	int &ans = memo[on][st];
	if(step[on][st] == curStep) return ans;
	step[on][st] = curStep;
	ans = std::max(dp(on+1, st), 1 + dp(on+1, trie[st][str[on] - 'a']));
	if(dp(on+1, st) >= 1 + dp(on+1, trie[st][str[on]-'a'])) {
		to[on][st] = 0;
	} else {
		to[on][st] = 1;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	addString(std::string("one"));
	addString(std::string("two"));
	for(int i = 1; i < c; i++) {
		for(int j = 0; j < 26; j++) {
			if(trie[i][j] == 0) {
				trie[i][j] = trie[0][j];
			}
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> str;
		curStep++;
		std::vector<int> ans;
		dp(0, 0);
		for(int i = 0, j = 0; i < (int) str.size(); i++) {
			if(to[i][j]) {
				j = trie[j][str[i]-'a'];
			} else {
				ans.push_back(i+1);
			}
		}
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}
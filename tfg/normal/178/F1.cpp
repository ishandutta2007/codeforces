#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>

typedef std::pair<int, int> ii;

int trieSize = 1;
int to[2001 * 501][26];
std::vector<ii> edges[2001 * 501];
std::bitset<2001 * 501> terminal;

void add(std::string str) {
	int on = 0;
	for(int i = 0; i < str.size(); i++) {
		//std::cout << on << ' ';
		if(to[on][str[i] - 'a'] == 0) {
			edges[on].emplace_back(trieSize, 0);
			to[on][str[i] - 'a'] = trieSize++;
		}
		on = to[on][str[i] - 'a'];
	}
	//std::cout << on << ' ' << trieSize << std::endl;
	terminal[trieSize] = true;
	edges[on].emplace_back(trieSize++, 0);
}

void pruneTree(int on) {
	//std::cout << "pruning on " << on << std::endl;
	if(edges[on].size() == 1) {
		//std::cout << "is bridge\n";
		while(edges[edges[on][0].first].size() == 1) {
			edges[on][0].second++;
			//std::cout << "was going to " << edges[on][0].first << ", is now going to " << edges[edges[on][0].first][0].first << std::endl;
			edges[on][0].first = edges[edges[on][0].first][0].first;
		}
	}
	for(auto e : edges[on]) {
		pruneTree(e.first);
	}
}

std::vector<int> dfs(int on) {
	//std::cout << "dfs on " << on << std::endl;
	if(terminal[on]) {
		//std::cout << "is terminal\n";
		return std::vector<int>(2, 0);
	}
	std::vector<int> curAnswer(1, 0);
	for(auto e : edges[on]) {
		auto trans = dfs(e.first);
		int n = curAnswer.size();
		int m = trans.size();
		std::vector<int> nxtAnswer(n + m - 1, 0);
		for(int i = 0; i < m; i++) {
			trans[i] += i * (i - 1) / 2 * e.second;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				nxtAnswer[i + j] = std::max(nxtAnswer[i + j], curAnswer[i] + trans[j]);
			}
		}
		curAnswer.swap(nxtAnswer);
	}
	//std::cout << "returning on " << on << std::endl;
	for(int i = 0; i < curAnswer.size(); i++) {
		curAnswer[i] += (on == 0 ? 0 : i * (i - 1) / 2);
		//std::cout << curAnswer[i] << (i + 1 == curAnswer.size() ? '\n' : ' ');
	}
	return curAnswer;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::string> words(n);
	for(int i = 0; i < n; i++) {
		std::cin >> words[i];
		add(words[i]);
	}
	pruneTree(0);
	std::vector<int> ans = dfs(0);
	std::cout << ans[k] << std::endl;
}
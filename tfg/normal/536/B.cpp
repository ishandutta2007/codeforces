#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> getBorder(std::string str) {
	int n = str.size();
	std::vector<int> border(n, -1);
	for(int i = 1, j = -1; i < n; i++) {
		while(j >= 0 && str[i] != str[j + 1]) {
			j = border[j];
		}
		if(str[i] == str[j + 1]) {
			j++;
		}
		border[i] = j;
	}
	return border;
}

std::vector<bool> matchPattern(const std::string &txt, const std::string &pat, const std::vector<int> &border) {
	std::vector<bool> ans(txt.size(), false);
	for(int i = 0, j = -1; i < (int) txt.size(); i++) {
		while(j >= 0 && txt[i] != pat[j + 1]) {
			j = border[j];
		}
		if(pat[j + 1] == txt[i]) {
			j++;
		}
		if(j + 1 == (int) pat.size()) {
			//found occurence in position i - pat.size() + 1
			ans[i - (int) pat.size() + 1] = true;
			j = border[j];
		}
	}
	return ans;
}

const int MOD = 1e9 + 7;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::string p;
	std::cin >> p;
	std::string txt(n, '?');
	std::set<int> mark;
	for(int i = 0; i < n; i++) {
		mark.insert(i);
	}
	std::vector<int> pos(m, 0);
	for(int i = 0; i < m; i++) {
		std::cin >> pos[i];
		pos[i]--;
		for(auto it = mark.lower_bound(pos[i]), end = mark.lower_bound(pos[i] + (int) p.size()); it != end; it++) {
			txt[*it] = p[*it - pos[i]];
		}
		mark.erase(mark.lower_bound(pos[i]), mark.lower_bound(pos[i] + (int) p.size()));
	}
	//std::cout << "txt is " << txt << std::endl;
	auto border = getBorder(p);
	auto got = matchPattern(txt, p, border);
	int ans = 1;
	for(int i = 0; i < m; i++) {
		if(!got[pos[i]]) {
			ans = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		if(txt[i] == '?') {
			ans = ans * 26LL % MOD;
		}
	}
	std::cout << ans << std::endl;
}
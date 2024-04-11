#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int c = 1;
int trie[100100][26];

void add(const std::string &str) {
	int on = 0;
	for(auto v : str) {
		int id = v - 'a';
		if(!trie[on][id]) {
			trie[on][id] = c++;
		}
		on = trie[on][id];
	}
}

int dfs(int on) {
	int ans = 0;
	bool got = false;
	for(int i = 0; i < 26; i++) {
		if(trie[on][i]) {
			got = true;
			ans |= dfs(trie[on][i]) ^ 3;
		}
	}
	if(!got) {
		ans = 2;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	while(n--) {
		std::string str;
		std::cin >> str;
		add(str);
	}
	int st = dfs(0);
	//std::cout << "st is " << st << "\n";
	if(st == 2 || st == 0) {
		std::cout << "Second\n";
	} else if(st == 1) {
		if(k % 2 == 1) {
			std::cout << "First\n";
		} else {
			std::cout << "Second\n";
		}
	} else {
		std::cout << "First\n";
	}
}
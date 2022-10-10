#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int trie[ms * 31][2], size[ms * 31];
int c = 1;

void add(int x) {
	int on = 0;
	for(int i = 29; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if(!trie[on][bit]) trie[on][bit] = c++;
		on = trie[on][bit];
		size[on]++;
		//std::cout << on << (i == 0 ? '\n' : ' ');
	}
}

int dp(int on) {
	if(!trie[on][0] && !trie[on][1]) {
		return 0;
	} else if(trie[on][0] && trie[on][1]) {
		int v0 = dp(trie[on][0]);
		int v1 = dp(trie[on][1]);
		int ans = std::min(v0 + size[trie[on][1]] - 1, v1 + size[trie[on][0]] - 1);
		return ans;
	} else {
		return dp(trie[on][0] ^ trie[on][1]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		int x;
		std::cin >> x;
		add(x);
	}
	std::cout << dp(0) << '\n';
}
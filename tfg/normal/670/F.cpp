#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int ALPHA = 10, class T = std::string, const int off = '0'>
struct Aho {
	struct Node {
		int to[ALPHA];
		int size;
		int fail, pfail;
		bool present;

		Node() {
			for(int i = 0; i < ALPHA; i++) {
				to[i] = 0;
			}
			size = 0;
			pfail = fail = 0;
			present = false;
			// maybe initialize some other stuff here
		}

		// maybe add some other stuff here
	};

	Aho() {
		nodes.push_back(Node());
	}

	int addString(const T &str) {
		int on = 0;
		for(auto ch : str) {
			if(nodes[on].to[ch-off] == 0) {
				nodes[on].to[ch-off] = (int) nodes.size();
				nodes.push_back(Node());
				nodes.back().size = 1 + nodes[on].size;
			}
			on = nodes[on].to[ch-off];
		}
		// makes this node present
		nodes[on].present = true;
		return on;
	}

	void build() {
		std::queue<int> que;
		que.push(0);
		while(!que.empty()) {
			int on = que.front();
			que.pop();
			nodes[on].pfail = nodes[nodes[on].fail].present ? nodes[on].fail : nodes[nodes[on].fail].pfail;
			// do stuff that carries over with fail here
			for(int i = 0; i < ALPHA; i++) {
				int &to = nodes[on].to[i];
				if(to) {
					nodes[to].fail = on == 0 ? 0 : nodes[nodes[on].fail].to[i];
					que.push(to);
				} else {
					to = nodes[nodes[on].fail].to[i];
				}
			}
		}
	}

	std::vector<Node> nodes;
};

int size(int x) { return x == 0 ? 0 : 1 + size(x / 10); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = 0;
	while(n + size(n) < (int) str.size()) {
		n++;
	}
	std::vector<int> freq(10, 0);
	for(auto c : str) {
		freq[c - '0']++;
	}
	{
		int x = n;
		while(x != 0) {
			freq[x % 10]--;
			x /= 10;
		}
	}
	std::cin >> str;
	std::vector<std::vector<int>> sum(str.size() + 1, std::vector<int>(10, 0));
	for(int i = (int) str.size()-1; i >= 0; i--) {
		for(int j = 0; j < 10; j++) {
			sum[i][j] = sum[i+1][j];
		}
		sum[i][str[i]-'0']++;
	}
	Aho<> trie;
	trie.addString(str);
	trie.build();
	std::string ans;
	bool lul = false;
	for(int i = 0, st = 0; i < n; i++) {
		if(st == (int) str.size()) {
			lul = true;
		}
		for(int j = (i+1==n || i ? 0 : 1); j < 10; j++) {
			bool valid = true;
			int toSt = trie.nodes[st].to[j];
			for(int k = 0; k < 10; k++) {
				valid = valid && freq[k] - (k==j?1:0) >= sum[toSt][k];
			}
			if(lul) {
				valid = freq[j] > 0;
			}
			if(valid) {
				freq[j]--;
				ans += char('0' + j);
				st = toSt;
				break;
			}
		}
	}
	std::cout << ans << '\n';
}
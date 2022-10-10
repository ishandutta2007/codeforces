#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int ALPHA = 26, class T = std::string, const int off = 'a'>
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
			freq = 0;
		}

		// maybe add some other stuff here
		int freq;
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

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string txt;
	std::cin >> txt;
	int n;
	std::cin >> n;
	Aho<> aho;
	while(n--) {
		std::string str;
		std::cin >> str;
		aho.nodes[aho.addString(str)].freq++;
	}
	n = (int) txt.size();
	std::vector<int> dp(n+1, 0);
	aho.build();
	for(int i = 0, j = 0; i < n; i++) {
		j = aho.nodes[j].to[txt[i]-'a'];
		int x = j;
		while(x > 0) {
			dp[i+1] += aho.nodes[x].freq;
			x = aho.nodes[x].pfail;
		}
	}
	long long ans = 0;
	for(int i = 0, j = 0; i < n; i++) {
		j = aho.nodes[j].to[txt[i]-'a'];
		int x = j;
		while(x > 0) {
			ans += (long long) aho.nodes[x].freq * dp[i-aho.nodes[x].size+1];
			x = aho.nodes[x].pfail;
		}
	}
	std::cout << ans << '\n';
}
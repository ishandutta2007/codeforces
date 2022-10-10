#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> good;

bool test(std::string &cur, int val) {
	for(int l = 0, r = 0, sum = 0; l < (int) cur.size(); l++) {
		while(r < (int) cur.size() && sum < val) sum += cur[r++] - '0';
		if(sum == val) return true;
		sum -= cur[l] - '0';
	}
	return false;
}

long long cnt = 0;

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

	template<class CH>
	int nextState(int on, CH ch) const {
		return nodes[on].to[ch - off];
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

Aho<> aho;

void gen(std::string &cur, int sum) {
	if(sum == 0) {
		for(auto wtf : good) {
			if(test(cur, wtf)) {
				return;
			}
		}
		//std::cout << "adding " << cur << " to the aho " << std::endl;
		cnt += (int) cur.size();
		aho.addString(cur);
	} else {
		for(int i = 1; i <= sum && i <= 9; i++) {
			cur += char('0' + i);
			gen(cur, sum - i);
			cur.pop_back();
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	if(0) {
		for(int x = 1; x <= 20; x++) {
			good.clear();
			for(int i = 1; i < x; i++) {
				if(x % i == 0) {
					good.push_back(i);
				}
			}
			std::string wtf;
			cnt = 0;
			gen(wtf, x);
			std::cout << "for " << x << " got " << cnt << std::endl;
		}
		return 0;
	}
	std::string txt;
	std::cin >> txt;
	int x;
	std::cin >> x;
	for(int i = 1; i < x; i++) {
		if(x % i == 0) good.push_back(i);
	}
	{
		std::string wtf;
		gen(wtf, x);
		aho.build();
	}
	//return 0;
	int n = (int) aho.nodes.size();
	std::vector<int> dp(n, 1e9);
	dp[0] = 0;
	for(auto ch : txt) {
		std::vector<int> nxt(n, 1e9);
		for(int i = 0; i < n; i++) {
			nxt[i] = std::min(nxt[i], dp[i] + 1);
			int o = aho.nextState(i, ch);
			if(!aho.nodes[o].present) nxt[o] = std::min(nxt[o], dp[i]);
		}
		nxt.swap(dp);
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++) {
		ans = std::min(ans, dp[i]);
	}
	std::cout << ans << '\n';
}
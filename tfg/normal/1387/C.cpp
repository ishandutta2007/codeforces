#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int ALPHA = 2, class T = std::vector<int>, const int off = 0>
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
			if(nodes[nodes[on].fail].present) nodes[on].present = true;
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

const int ms = 103;
const unsigned long long INF = (1LL << 63);

std::vector<std::vector<int>> rules[ms], special[ms];
unsigned long long dp[ms][ms][ms];
unsigned long long tmp[2][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cerr << INF << '\n';
	int n, m, k;
	std::cin >> n >> m >> k;
	assert(n <= ms);
	while(m--) {
		int a, size;
		std::cin >> a >> size;
		int mx = 0;
		std::vector<int> rule;
		while(size--) {
			int x;
			std::cin >> x;
			mx = std::max(x, mx);
			rule.push_back(x);
		}
		if(mx <= 1) {
			special[a].push_back(rule);
		} else {
			rules[a].push_back(rule);
		}
	}
	special[0].push_back(std::vector<int>(1, 0));
	special[1].push_back(std::vector<int>(1, 1));
	Aho<> aho;
	while(k--) {
		int size;
		std::cin >> size;
		std::vector<int> anti;
		while(size--) {
			int x;
			std::cin >> x;
			assert(x == 0 || x == 1);
			anti.push_back(x);
		}
		aho.addString(anti);
	}
	aho.build();
	for(int i = 0; i < ms; i++) for(int j = 0; j < ms; j++) for(int jj = 0; jj < ms; jj++) dp[i][j][jj] = INF;
	m = (int) aho.nodes.size();
	for(int i = 0; i < n; i++) {
		for(auto endString : special[i]) {
			for(int j = 0; j < m; j++) {
				int st = j;
				for(auto ch : endString) {
					if(aho.nodes[st].pfail != 0 || aho.nodes[st].present) {
						st = -1;
						break;
					}
					st = aho.nextState(st, ch);
					if(aho.nodes[st].pfail != 0 || aho.nodes[st].present) {
						st = -1;
						break;
					}
				}
				if(st != -1) {
					dp[i][j][st] = std::min(dp[i][j][st], (unsigned long long) endString.size());
				}
			}
		}
	}
	std::vector<int> perm;
	for(int i = 2; i < n; i++) {
		perm.push_back(i);
	}
	for(int rep = 0; 1; rep++) {
		//assert(rep < ms);
		if(rep % 3 == 0) std::sort(perm.begin(), perm.end());
		else if(rep % 3 == 1) std::shuffle(perm.begin(), perm.end(), rng);
		else std::sort(perm.rbegin(), perm.rend());
		bool run = false;
		for(auto i : perm) {
			for(int j = 0; j < m; j++) {
				for(auto rule : rules[i]) {
					for(int ii = 0; ii < m; ii++) {
						tmp[0][ii] = tmp[1][ii] = INF;
					}
					tmp[0][j] = 0;
					for(auto ch : rule) {
						for(int ii = 0; ii < m; ii++) if(tmp[0][ii] < INF) for(int jj = 0; jj < m; jj++) {
							tmp[1][jj] = std::min(tmp[1][jj], tmp[0][ii] + dp[ch][ii][jj]);
						}
						for(int ii = 0; ii < m; ii++) {
							tmp[0][ii] = tmp[1][ii];
							tmp[1][ii] = INF;
						}
					}
					for(int ii = 0; ii < m; ii++) {
						if(dp[i][j][ii] > tmp[0][ii]) {
							dp[i][j][ii] = tmp[0][ii];
							run = true;
						}
					}
				}
			}
		}
		if(!run) break;
	}
	for(int i = 2; i < n; i++) {
		unsigned long long mx = INF;
		for(int j = 0; j < m; j++) {
			mx = std::min(mx, dp[i][0][j]);
		}
		if(mx == INF) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO " << mx << "\n";
		}
	}
}
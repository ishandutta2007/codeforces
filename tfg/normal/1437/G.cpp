#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <set>

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
		}

		// maybe add some other stuff here
		std::multiset<int> st;
		int val = 0;
	};

	Aho() {
		nodes.push_back(Node());
	}

	template<class F>
	void goUp(int on, F f) {
		for(on = nodes[on].present ? on : nodes[on].pfail; on > 0; on = nodes[on].pfail) {
			f(nodes[on]);
		}
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	Aho<> aho;
	std::vector<int> pos(n);
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		pos[i] = aho.addString(str);
	}
	aho.build();
	for(int i = 0; i < n; i++) {
		aho.nodes[pos[i]].st.insert(0);
	}
	while(m--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int i;
			std::cin >> i;
			i--;
			int val;
			std::cin >> val;
			aho.nodes[pos[i]].st.erase(aho.nodes[pos[i]].st.find(a[i]));
			a[i] = val;
			aho.nodes[pos[i]].st.insert(a[i]);
			aho.nodes[pos[i]].val = *aho.nodes[pos[i]].st.rbegin();
		} else {
			std::string str;
			std::cin >> str;
			int ans = -1;
			auto f = [&](auto &node) { ans = std::max(ans, node.val); };
			int on = 0;
			for(auto ch : str) {
				on = aho.nextState(on, ch);
				aho.goUp(on, f);
			}
			std::cout << ans << '\n';
		}
	}
}
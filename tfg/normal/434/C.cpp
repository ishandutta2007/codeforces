#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 220;

template<const int ALPHA, class T = std::string, const int off = 'a'>
struct Aho {
	struct Node {
		int to[ALPHA];
		int fail, pfail;
		bool present;

		Node() {
			for(int i = 0; i < ALPHA; i++) {
				to[i] = 0;
			}
			pfail = fail = 0;
			present = false;
			// maybe initialize some other stuff here
			value = 0;
		}

		// maybe add some other stuff here
		int value;
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
			nodes[on].value += nodes[nodes[on].fail].value;
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

int l[ms], r[ms];

int dp[ms][ms][505];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	{
		// reading l
		int len;
		std::cin >> len;
		while(len > 0) {
			std::cin >> l[ms-len];
			len--;
		}
		l[ms-1]--;
		for(int i = ms-1; l[i] < 0; i--) {
			l[i] += m;
			l[i-1]--;
		}
	}
	{
		// reading r
		int len;
		std::cin >> len;
		while(len > 0) {
			std::cin >> r[ms-len];
			len--;
		}
	}
	Aho<20, std::vector<int>, 0> aho;
	while(n--) {
		int len;
		std::cin >> len;
		std::vector<int> str(len);
		for(auto &v : str) std::cin >> v;
		int v;
		std::cin >> v;
		aho.nodes[aho.addString(str)].value += v;
	}
	aho.build();
	{
		// precalculate dp
		for(int i = 0; i < (int) aho.nodes.size(); i++) {
			for(int j = 0; j <= k; j++) {
				dp[0][i][j] = 1;
			}
		}
		for(int i = 1; i < ms; i++) {
			for(int j = 0; j < (int) aho.nodes.size(); j++) {
				for(int val = 0; val <= k; val++) {
					for(int ch = 0; ch < m; ch++) {
						int newState = aho.nodes[j].to[ch];
						int newCost = val - aho.nodes[newState].value;
						if(newCost >= 0) {
							dp[i][j][val] = (dp[i][j][val] + dp[i-1][newState][newCost]) % MOD;
						}
					}
					//std::cout << "(" << i << ", " << j << ", " << val << ") has " << dp[i][j][val] << '\n';
				}
			}
		}
	}
	int ans = 0;
	{
		bool wtf = false;
		int st = 0;
		int sum = k;
		for(int on = 0; on < ms; on++) {
			if(!wtf && r[on] == 0) {
				continue;
			}
			//std::cout << r[on] << '\n';
			for(int i = (wtf ? 0 : 1); i < r[on]; i++) {
				int newState = aho.nodes[st].to[i];
				int newCost = sum - aho.nodes[newState].value;
				if(newCost >= 0) {
					ans = (ans + dp[ms-on-1][newState][newCost]) % MOD;
					//std::cout << "adding state (" << ms-on-1 << ", " << newState << ", " << newCost << ") with " << dp[ms-on-1][newState][newCost] << '\n';
				}
			}
			st = aho.nodes[st].to[r[on]];
			sum -= aho.nodes[st].value;
			if(wtf) {
				for(int i = 1; i < m; i++) {
					int newState = aho.nodes[0].to[i];
					int newCost = k - aho.nodes[newState].value;
					if(newCost >= 0) {
						//std::cout << "adding state (" << ms-on-1 << ", " << newState << ", " << newCost << ") with " << dp[ms-on-1][newState][newCost] << '\n';
						ans = (ans + dp[ms-on-1][newState][newCost]) % MOD;
					}
				}
			}
			wtf = true;
		}
		//std::cout << std::endl;
		if(sum >= 0) {
			ans = (ans + 1) % MOD;
		}
	}
	{
		bool wtf = false;
		int st = 0;
		int sum = k;
		for(int on = 0; on < ms; on++) {
			if(!wtf && l[on] == 0) {
				continue;
			}
			//std::cout << l[on] << '\n';
			for(int i = (wtf ? 0 : 1); i < l[on]; i++) {
				int newState = aho.nodes[st].to[i];
				int newCost = sum - aho.nodes[newState].value;
				if(newCost >= 0) {
					ans = (ans - dp[ms-on-1][newState][newCost]) % MOD;
					//std::cout << "removing state (" << ms-on-1 << ", " << newState << ", " << newCost << ") with " << dp[ms-on-1][newState][newCost] << '\n';
				}
			}
			st = aho.nodes[st].to[l[on]];
			sum -= aho.nodes[st].value;
			if(wtf) {
				for(int i = 1; i < m; i++) {
					int newState = aho.nodes[0].to[i];
					int newCost = k - aho.nodes[newState].value;
					if(newCost >= 0) {
						ans = (ans - dp[ms-on-1][newState][newCost]) % MOD;
						//std::cout << "renoving state (" << ms-on-1 << ", " << newState << ", " << newCost << ") with " << dp[ms-on-1][newState][newCost] << '\n';
					}
				}
			}
			wtf = true;
		}
		//std::cout << std::endl;
		if(wtf && sum >= 0) {
			ans = (ans - 1 + MOD) % MOD;
		}
	}
	ans = (ans % MOD + MOD) % MOD;
	std::cout << ans << std::endl;
}
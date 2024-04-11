#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];

struct DP {
	struct Node {
		Node(int x = 0) {
			if(x == 0) {
				size = 0;
				ans = 0;
			} else if(x > 0) {
				a[0] = x;
				size = 1;
				ans = 0;
			} else {
				size = 0;
				ans = -ms;
			}
		}

		Node operator + (const Node &o) const {
			Node anss = *this;
			for(int i = 0; i < o.size; i++) {
				anss.a[anss.size++] = o.a[i];
			}
			anss.ans += o.ans;
			return anss;
		}

		bool operator < (const Node &o) const { return ans != o.ans ? ans < o.ans : size < o.size; }
		int size, ans;
		int a[3];
		void print() {
			assert(size == 3);
			std::cout << ans << '\n';
			std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
		}
	};
	Node dp[4];
	DP(int val) {
		dp[0] = Node(0);
		dp[1] = Node(val);
		dp[2] = dp[3] = Node(-1);
	}
	DP(DP l, DP r) {
		r.dp[1].ans++;
		r.dp[2].ans++;
		dp[0] = 0;
		dp[3] = std::max(std::max(l.dp[3], r.dp[3]), std::max(l.dp[2] + r.dp[1], l.dp[1] + r.dp[2]));
		dp[2] = std::max(std::max(l.dp[2], r.dp[2]), l.dp[1] + r.dp[1]);
		dp[1] = std::max(l.dp[1], r.dp[1]);
	}
};

DP dfs(int on, int par) {
	DP cur(on+1);
	for(auto to : edges[on]) {
		if(to != par) cur = DP(cur, dfs(to, on));
	}
	return cur;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0).dp[3].print();
}
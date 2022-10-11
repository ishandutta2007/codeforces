#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 300200;

int dp[2][ms][2];

struct Min_Queue {
	std::vector<ii> q;
	int l, size;

	void init() {
		q.clear();
		l = 0;
		size = 0;
	}

	void push(int val) {
		int freq = 1;
		while(q.size() > l && q.back().first >= val) {
			freq += q.back().second;
			q.pop_back();
		}
		q.emplace_back(val, freq);
		size++;
	}

	void pop() {
		if(l == q.size()) {
			std::cout << "deu merda\n";
		}
		q[l].second--;
		if(q[l].second == 0) {
			l++;
		}
		size--;
	}

	int top() {
		if(l == q.size()) {
			return 1e9;
		}
		return q[l].first;
	}
};

int main() {
	int n, k;
	std::cin >> n >> k;
	memset(dp[0], 0x3f, sizeof dp[0]);
	dp[0][0][0] = 0;
	int last = 0;
	Min_Queue q;
	for(int i = 1; i <= k; i++) {
		int now = i & 1;
		int old = 1 - now;
		memset(dp[now], 0x3f, sizeof dp[now]);
		int l, r;
		std::cin >> l >> r;
		for(int j = 0; j <= n; j++) {
			dp[now][j + r - last][0] = std::min(dp[now][j + r - last][0], dp[old][j][0]);
			dp[now][j][1] = std::min(dp[now][j][1], dp[old][j][1]);
		}
		q.init();
		for(int j = l - last; j <= n; j++) {
			if(q.size > r - l) {
				q.pop();
			}
			q.push(dp[old][j - (l - last)][0]);
			dp[now][j][1] = std::min(dp[now][j][1], q.top() + 1);
		}
		q.init();
		for(int j = 0; j <= n; j++) {
			if(q.size > r - l) {
				q.pop();
			}
			q.push(dp[old][j][1]);
			dp[now][j][0] = std::min(dp[now][j][0], q.top() + 1);
		}
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k < 2; k++) {
				dp[now][j][k] = std::min(dp[now][j][1 - k] + 1, dp[now][j][k]);
			}
		}
		/*std::cout << "------------------------------------\n";
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k < 2; k++) {
				std::cout << dp[now][j][k] << ' ';
			}
			std::cout << '\n';
		}*/
		last = r;
	}
	int ans = dp[k & 1][n][1];
	if(n - (2 * n - last) >= 0) {
		//std::cout << "getting from " << n - (2 * n - last) << "\n";
		ans = std::min(ans, dp[k & 1][n - (2 * n - last)][0]);
	}
	if(ans > 2 * n) {
		std::cout << "Hungry\n";
	} else {
		std::cout << "Full\n" << ans << '\n';
	}
}
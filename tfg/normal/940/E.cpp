#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 100100;

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

int a[ms];
long long dp[ms];

int main() {
	int n, c;
	std::cin >> n >> c;
	Min_Queue q;
	q.init();
	long long ans = 0, sum = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		q.push(a[i]);
		if(i >= c) {
			dp[i] = dp[i - c] + q.top();
			//std::cout << q.top() << "on " << i << "\n";
			q.pop();
		}
		dp[i] = std::max(dp[i], dp[i - 1]);
		sum += a[i];
		ans = std::max(ans, dp[i]);
	}
	std::cout << sum - ans << '\n';
}
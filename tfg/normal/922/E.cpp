#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdio>

typedef long long ll;
typedef std::pair<ll, int> ii;

struct Max_Queue {
	std::vector<ii> q;
	int l;

	void init() {
		q.clear();
		l = 0;
	}

	void push(ll val) {
		int freq = 1;
		while(q.size() > l && q.back().first <= val) {
			freq += q.back().second;
			q.pop_back();
		}
		q.emplace_back(val, freq);
	}

	void pop() {
		q[l].second--;
		if(q[l].second == 0) {
			l++;
		}
	}

	ll top() {
		if(l == q.size()) {
			return -1e18;
		}
		return q[l].first;
	}
};

Max_Queue q;

ll dp[1010][10010];
int c[1010];
ll cost[1010];

int main() {
	int n;
	std::cin >> n;
	ll ini, up, rest;
	std::cin >> ini >> up >> rest;
	memset(dp, -1, sizeof dp);
	dp[0][0] = ini;
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		//std::cin >> c[i];
		scanf("%i", c + i);
	}
	for(int i = 1; i <= n; i++) {
		//std::cin >> cost[i];
		scanf("%lli", cost + i);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= tot; j++) {
			if(dp[i - 1][j] >= 0) {
				dp[i - 1][j] = std::min(ini + j * up, dp[i - 1][j] + rest);
			} else {
				tot = j - 1;
				break;
			}
		}
		tot += c[i];
		q.init();
		dp[i][0] = ini;
		q.push(ini);
		int l = 0;
		for(int j = 1; j <= tot; j++) {
			if(tot - c[i] >= j)
				q.push(dp[i - 1][j] + cost[i] * j);
			while(j - l > c[i]) {
				q.pop();
				l++;
			}
			dp[i][j] = -j * cost[i] + q.top();
			if(dp[i][j] < 0) {
				tot = j - 1;
				break;
			}
		}
	}
	std::cout << tot << '\n';
}
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T, class C = std::less<T>>
struct MaxQueue {
	MaxQueue() {
		clear();
	}

	int size() { return (int) q.size(); }

	void clear() {
		id = 0;
		q.clear();
	}

	void push(T x) {
		std::pair<int, T> nxt(1, x);
		while((int) q.size() > id && cmp(q.back().second, x)) {
			nxt.first += q.back().first;
			q.pop_back();
		}
		q.push_back(nxt);
	}

	T qry() {
		return q[id].second;
	}

	void pop() {
		q[id].first--;
		if(q[id].first == 0) {
			id++;
		}
	}
private:
	std::vector<std::pair<int, T>> q;
	int id;
	C cmp;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1001000;
	const long long INF = 1e18;
	int n;
	std::cin >> n;
	int cost[6];
	for(int i = 0; i < 6; i++) {
		std::cin >> cost[5-i];
	}
	std::vector<long long> dp(ms, -INF);
	dp[0] = 0;
	for(int rep = 0; rep < 6; rep++) {
		long long curCost = cost[rep];
		// fixing dp
		for(int i = ms-1; i > 0; i--) {
			dp[i] = i % 10 == 0 ? dp[i / 10] : -INF;
		}
		std::vector<long long> nxt(ms, -INF);
		// doing smart transition
		int MAGIC = 9 * (n-1);
		MaxQueue<long long> q[3];
		for(int i = 0; i < ms; i++) {
			if(i - MAGIC - 1 >= 0) {
				q[(i - MAGIC - 1) % 3].pop();
			}
			q[i%3].push(dp[i] - curCost * (i / 3));
			nxt[i] = q[i%3].qry() + curCost * (i / 3);
		}
		// doing brute transition
		for(int i = ms-1; i > 0; i--) {
			for(int j = 1; j <= 9 && j <= i; j++) {
				nxt[i] = std::max(nxt[i], nxt[i-j] + (j % 3 == 0 ? j / 3 : 0) * curCost);
			}
		}
		dp = nxt;
	}
	int q;
	std::cin >> q;
	while(q--) {
		int wtf;
		std::cin >> wtf;
		std::cout << dp[wtf] << '\n';
	}
}
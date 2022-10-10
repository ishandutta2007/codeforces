#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T, class C = std::less<T>>
struct MaxQueue {
	MaxQueue() {
		clear();
	}

	void clear() {
		id = 0;
		q.clear();
	}

	void push(T x) {
		std::pair<int, T> nxt(1, x);
		while(q.size() > id && cmp(q.back().second, x)) {
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
	int n, k, x;
	std::cin >> n >> k >> x;
	if(n / k > x) {
		std::cout << "-1\n";
		return 0;
	}
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	const long long INF = 1e18;
	std::vector<long long> dp(n + 1, -INF);
	while(x--) {
		dp[0] = 0;
		MaxQueue<long long> q;
		q.push(0);
		for(int i = 1; i <= n; i++) {
			long long v = dp[i];
			//std::cout << "val for " << i << " is " << v << "\n";
			dp[i] = q.qry() + a[i-1];
			if(i >= k) {
				q.pop();
			}
			q.push(v);
		}
	}
	long long ans = -INF;
	for(int i = 0; i < k; i++) {
		ans = std::max(ans, dp[n-i]);
	}
	std::cout << ans << '\n';
}
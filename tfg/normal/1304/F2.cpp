#include <iostream>
#include <vector>
#include <chrono>
#include <random>

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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<long long>> a(n + 1, std::vector<long long>(m + 1, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j+1];
			a[i][j+1] += a[i][j];
		}
	}
	int sizes = m-k + 1;
	std::vector<long long> dp(sizes);
	for(int i = 0; i < sizes; i++) {
		dp[i] = a[0][i+k] - a[0][i] + a[1][i+k] - a[1][i];
	}
	for(int i = 1; i < n; i++) {
		std::vector<long long> nxt(sizes, -1e18);
		// j-th position with before
		{
			long long bst = -1e18;
			MaxQueue<long long> q;
			for(int j = 0; j < sizes; j++) {
				// including j-th
				q.push(-a[i][j+k] + dp[j]);
				// removing (j-k)-th
				if(j-k >= 0) {
					q.pop();
					bst = std::max(bst, dp[j-k]);
				}
				nxt[j] = std::max(nxt[j], bst + a[i][j+k] - a[i][j] + a[i+1][j+k] - a[i+1][j]);
				nxt[j] = std::max(nxt[j], q.qry() + a[i][j+k] + a[i+1][j+k] - a[i+1][j]);
			}
		}
		// j-th position with after
		{
			long long bst = -1e18;
			MaxQueue<long long> q;
			for(int j = sizes-1; j >= 0; j--) {
				// including j-th
				q.push(a[i][j] + dp[j]);
				// removing (j+k)-th
				if(j+k < sizes) {
					q.pop();
					bst = std::max(bst, dp[j+k]);
				}
				nxt[j] = std::max(nxt[j], bst + a[i][j+k] - a[i][j] + a[i+1][j+k] - a[i+1][j]);
				nxt[j] = std::max(nxt[j], q.qry() - a[i][j] + a[i+1][j+k] - a[i+1][j]);
			}
		}
		dp.swap(nxt);
	}
	long long ans = 0;
	for(int i = 0; i < sizes; i++) {
		ans = std::max(ans, dp[i]);
	}
	std::cout << ans << std::endl;
}
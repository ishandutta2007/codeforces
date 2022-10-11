#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;

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
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, d;
	std::cin >> n >> m >> d;
	std::vector<ii> fire(m);
	long long base = 0;
	for(int i = 0; i < m; i++) {
		int a, b, t;
		std::cin >> a >> b >> t;
		fire[i] = ii(t, a - 1);
		base += b;
	}
	std::vector<long long> dp(n, base);
	int cur_t = 1;
	auto shift = [](const std::vector<long long> &v, int d) {
		//std::cout << "making shift of " << d << std::endl;
		int n = v.size();
		d = std::min(d, n - 1);
		std::vector<long long> ans(n);
		MaxQueue<long long> q;
		for(int i = 0; i <= d; i++) {
			//std::cout << "pushing pos " << i << std::endl;
			q.push(v[i]);
		}
		for(int i = 0; i < n; i++) {
			ans[i] = q.qry();
			if(i >= d) {
				//std::cout << "popping pos " << i - d << std::endl;
				q.pop();
			}
			if(i + d + 1 < n) {
				//std::cout << "pushing pos " << i + d + 1 << std::endl;
				q.push(v[i + d + 1]);
			}
		}
		return ans;
	};
	for(int i = 0; i < m; i++) {
		int pos = fire[i].second;
		int nxt_t = fire[i].first;
		//std::cout << "got qry (" << pos << ", " << nxt_t << ")\n";
		dp = shift(dp, std::min((long long)(nxt_t - cur_t) * d, n - 1LL));
		for(int j = 0; j < n; j++) {
			dp[j] -= abs(pos - j);
		}
		cur_t = nxt_t;
	}
	long long ans = dp[0];
	for(int i = 0; i < n; i++) {
		ans = std::max(ans, dp[i]);
	}
	std::cout << ans << std::endl;
}
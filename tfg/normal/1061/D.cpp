#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 1e9 + 7;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, x, y;
	std::cin >> n >> x >> y;
	std::vector<int> start(n), end(n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> start[i] >> end[i];
		ans += (long long) (end[i] - start[i]) * y % MOD;
		ans %= MOD;
	}
	std::sort(start.begin(), start.end());
	std::sort(end.begin(), end.end());
	int ss = 0, se = 0;
	std::priority_queue<int> hp;
	while(ss < n && se < n) {
		if(end[se] < start[ss]) {
			int t = end[se++];
			//std::cout << "ending in time " << t << '\n';
			// insert end
			hp.push(t);
		} else {
			int t = start[ss++];
			//std::cout << "starting in time " << t << '\n';
			while(!hp.empty() && (long long) (t - hp.top()) * y >= x) {
				//std::cout << "popping time " << hp.top() << '\n';
				hp.pop();
			}
			if(hp.empty()) {
				// create new
				//std::cout << "creating new\n";
				ans = (ans + x) % MOD;
			} else {
				// use old
				//std::cout << "using old of time " << hp.top() << '\n';
				ans = (ans + (long long) (t - hp.top()) * y) % MOD;
				hp.pop();
			}
		}
	}
	std::cout << ans << '\n';
}
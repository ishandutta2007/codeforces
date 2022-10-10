#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long a, rr, m;
	std::cin >> n >> a >> rr >> m;
	std::vector<long long> h(n);
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	auto getEvents = [&](long long x) {
		std::pair<long long, long long> ans(0, 0);
		for(auto y : h) {
			if(y < x) {
				ans.first += x - y;
			} else {
				ans.second += y - x;
			}
		}
		return ans;
	};
	auto getCost = [&](long long x) {
		auto events = getEvents(x);
		long long ans = 0;
		if(m < rr + a) {
			long long use = std::min(events.first, events.second);
			events.first -= use;
			events.second -= use;
			ans += use * m;
		}
		ans += events.first * a + events.second * rr;
		//std::cout << "at " << x << " got cost " << ans << '\n';
		return ans;
	};
	// get splitting point, -INF has more removes than adds
	long long l = 0, r = 1e9;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		auto got = getEvents(mid);
		bool good = got.first <= got.second;
		if(good) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	long long split = l;
	long long ans = getCost(split);
	for(int rep = 0; rep < 2; rep++) {
		if(rep == 0) {
			l = 0, r = split;
		} else {
			l = split + 1, r = 1e9 + 1;
		}
		while(l != r) {
			long long mid = (l + r) / 2;
			if(getCost(mid) <= getCost(mid+1)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = std::min(ans, getCost(l));
	}
	std::cout << ans << '\n';
}
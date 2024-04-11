#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> a;

struct Event {
	Event(int x = 0, int y = 0) {
		mx = x;
		val = y;
	}
	int mx, val;
	bool operator < (const Event &e) const { return mx < e.mx; }
};

int curStep = 0;
int step[200200];

long long solve(int l, int r) {
	if(r - l <= 20) {
		long long ans = 0;
		for(int i = l; i < r; i++) {
			int mx = 0;
			for(int j = i; j < r; j++) {
				mx = std::max(mx, a[j]);
				if(a[i] + a[j] == mx) {
					ans++;
				}
			}
		}
		return ans;
	}
	int mid = (l + r) / 2;
	long long ans = solve(l, mid) + solve(mid, r);
	std::vector<Event> events1, events2;
	int mx = 0;
	for(int i = mid; i < r; i++) {
		mx = std::max(mx, a[i]);
		events1.emplace_back(mx, a[i]);
	}
	mx = 0;
	for(int i = mid - 1; i >= l; i--) {
		mx = std::max(mx, a[i]);
		events2.emplace_back(mx, -a[i]);
	}
	std::vector<Event> events;
	events.resize(r - l);
	std::merge(events1.begin(), events1.end(), events2.begin(), events2.end(), events.begin());
	curStep++;
	for(auto e : events) {
		if(e.val < 0) {
			e.val = -e.val;
			int id = curStep * 2;
			int want = e.mx - e.val;
			if(step[want] == (id^1)) {
				ans++;
			}
			step[e.val] = id;
		} else {
			int id = curStep * 2 + 1;
			int want = e.mx - e.val;
			if(step[want] == (id^1)) {
				ans++;
			}
			step[e.val] = id;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << solve(0, n) << '\n';
}
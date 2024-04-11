#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
	long long pos;
	int val;

	Event(long long pos, int val) : pos(pos), val(val) {}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<Event> events;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		long long l, r;
		std::cin >> l >> r;
		events.emplace_back(l, 1);
		events.emplace_back(r + 1, -1);
	}
	std::sort(events.begin(), events.end(), [](Event a, Event b) { return a.pos < b.pos; });
	long long pos = -1;
	int f = 0;
	std::vector<long long> ans(n + 1, 0);
	for(int l = 0, r = 0; l < events.size(); l = r) {
		if(l == 0) {
			pos = events[0].pos;
		}
		ans[f] += (events[l].pos - pos);
		while(r < events.size() && events[l].pos == events[r].pos) {
			f += events[r++].val;
		}
		pos = events[l].pos;
	}
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << (i == n ? '\n' : ' ');
	}
}
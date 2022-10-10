#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct Info {
	Info(int a, int b, int x) {
		c = a, f = b, id = x;
	}
	int f, c, id;

	bool operator < (Info o) const { return c < o.c; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, s;
	std::cin >> n >> m >> s;
	std::vector<int> a(m);
	std::vector<int> b(n), c(n);
	std::vector<int> events(m + n);
	for(int i = 0; i < m; i++) {
		std::cin >> a[i];
		events[i] = i;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		events[m + i] = m + i;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	auto getCost = [&](int x) {
		if(x < m) {
			return a[x] * 2;
		} else {
			return b[x - m] * 2 + 1;
		}
	};
	std::sort(events.begin(), events.end(), [&](int x, int y){ return getCost(x) > getCost(y); });
	for(auto e : events) {
		//std::cout << e << '\n';
	}
	std::vector<int> haha(m);
	auto test = [&](int x) {
		long long ans = 0;
		std::priority_queue<Info> hp;
		//std::cout << "testing for " << x << "\n";
		int y = 0, hmm;
		for(auto e : events) {
			if(e < m) {
				if(y) {
					y--;
					haha[e] = hmm;
					continue;
				}
				while(!hp.empty() && hp.top().f == 0) hp.pop();
				if(hp.empty()) return (long long) INF;
				auto cur = hp.top();
				hp.pop();
				ans -= cur.c;
				cur.f--;
				haha[e] = cur.id;
				//std::cout << "got cost " << -cur.c << " with freq " << cur.f << "\n";
				if(cur.f > 0) {
					y += cur.f;
					hmm = cur.id;
					//hp.push(cur);
				}
			} else {
				//std::cout << "adding (" << c[e - m] << ", " << x << ", " << e - m << ") in heap\n";
				hp.push(Info(-c[e - m], x, e - m));
			}
		}
		//std::cout << "for " << x << " days, returning " << ans << '\n';
		return ans;
	};
	int l = 1, r = m + 1;
	while(l != r) {
		int mid = (l + r) / 2;
		if(test(mid) <= s) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if(l > m) {
		std::cout << "NO\n";
		return 0;
	}
	test(l);
	std::cout << "YES\n";
	for(int i = 0; i < m; i++) {
		std::cout << haha[i] + 1 << (i + 1 == m ? '\n' : ' ');
	}
}
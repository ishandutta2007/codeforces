#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int col[ms];
std::vector<int> edges[ms];

void bicol(int u) {
	for(auto v : edges[u]) {
		if(col[v] == -1) {
			col[v] = col[u];
			bicol(v);
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		col[i] = -1;
		edges[i].clear();
	}
	struct Event {
		int pos, id, t;
		bool operator < (Event o) const {
			return pos != o.pos ? pos < o.pos : t < o.t;
		}
	};
	std::vector<Event> events;
	for(int i = 0; i < n; i++) {
		int l, r;
		std::cin >> l >> r;
		r++;
		Event cur;
		cur.pos = l;
		cur.id = i;
		cur.t = 1;
		events.push_back(cur);
		cur.pos = r;
		cur.t = -1;
		events.push_back(cur);
	}
	std::sort(events.begin(), events.end());
	std::vector<int> wtf;
	for(auto e : events) {
		if(e.t == 1) {
			for(auto v : wtf) {
				edges[v].push_back(e.id);
				edges[e.id].push_back(v);
				break;
			}
			wtf.push_back(e.id);
		} else {
			int i = 0;
			while(wtf[i] != e.id) i++;
			std::swap(wtf[i], wtf.back());
			wtf.pop_back();
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(col[i] == -1) {
			col[i] = count++;
			bicol(i);
		}
	}
	if(count > 1) {
		for(int i = 0; i < n; i++) {
			std::cout << col[i] % 2 + 1 << (i + 1 == n ? '\n' : ' ');
		}
	} else {
		std::cout << "-1\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}
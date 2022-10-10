#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

std::vector<int> ends;
std::vector<int> tree[ms], qries[ms];
int other[ms];

struct Solution {
	Solution() {
		cost = 0;
	}

	void addPoint(int x) {
		buffer.push_back(x);
	}

	int qry(int x) {
		int ans = std::upper_bound(order.begin(), order.end(), x) - order.begin();
		for(auto v : buffer) {
			if(v <= x) {
				ans++;
			}
		}
		cost += (int) buffer.size();
		if(cost > 4 * (int) (buffer.size() + order.size())) {
			std::sort(buffer.begin(), buffer.end());
			std::merge(buffer.begin(), buffer.end(), order.begin(), order.end(), other);
			order.resize(order.size() + buffer.size());
			for(int i = 0; i < (int) order.size(); i++) {
				order[i] = other[i];
			}
			cost = 0;
			buffer.clear();
		}
		return ans;
	}

	int cost;
	std::vector<int> order, buffer;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n), s(n), b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::vector<int> inc(m), pref(m);
	for(int i = 0; i < m; i++) {
		std::cin >> inc[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> pref[i];
	}
	// ranges are [p[i], s[i] + 1), put them into ends
	// also insert query points inc[i]
	{
		for(int i = 0; i < n; i++) {
			s[i]++;
			ends.push_back(p[i]);
			ends.push_back(s[i]);
		}
		for(int i = 0; i < m; i++) {
			ends.push_back(inc[i]);
		}
		std::sort(ends.begin(), ends.end());
		ends.resize(std::unique(ends.begin(), ends.end()) - ends.begin());
	}
	auto getID = [&](int x) {
		return std::lower_bound(ends.begin(), ends.end(), x) - ends.begin();
	};
	// construct segment tree, updating the ranges with points (p + b, p - b)
	{
		std::vector<int> perm(n);
		for(int i = 0; i < n; i++) {
			perm[i] = i;
		}
		std::sort(perm.begin(), perm.end(), [&](int v1, int v2) { return p[v1] + b[v1] < p[v2] + b[v2]; });
		for(auto x : perm) {
			int l = getID(p[x]);
			int r = getID(s[x]);
			l += (int) ends.size();
			r += (int) ends.size();
			for(; l < r; l /= 2, r /= 2) {
				if(l & 1) {
					tree[l++].push_back(x);
				}
				if(r & 1) {
					tree[--r].push_back(x);
				}
			}
		}
	}
	// set queries with (inc + pref, inc - pref)
	{
		std::vector<int> perm(m);
		for(int i = 0; i < m; i++) {
			perm[i] = i;
		}
		std::sort(perm.begin(), perm.end(), [&](int v1, int v2) { return inc[v1] + pref[v1] < inc[v2] + pref[v2]; });
		for(auto x : perm) {
			int id = (int) ends.size() + getID(inc[x]);
			while(id > 0) {
				qries[id].push_back(x);
				id /= 2;
			}
		}
	}
	// answer queries offline
	std::vector<int> ans(m, 0);
	for(int i = 1; i < 2 * (int) ends.size(); i++) {
		if(qries[i].empty() || tree[i].empty()) {
			continue;
		}
		Solution solve;
		int pt = 0;
		for(auto q : qries[i]) {
			while(pt < (int) tree[i].size() && p[tree[i][pt]] + b[tree[i][pt]] <= inc[q] + pref[q]) {
				solve.addPoint(p[tree[i][pt]] - b[tree[i][pt]]);
				pt++;
			}
			ans[q] += solve.qry(inc[q] - pref[q]);
		}
	}
	// print answer and pray for AC
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << (i + 1 == m ? '\n' : ' ');
	}
}
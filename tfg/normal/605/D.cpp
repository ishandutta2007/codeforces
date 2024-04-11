#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200100;

std::vector<int> all;
std::vector<std::pair<int, int>> tree[ms];

int a[ms], b[ms], c[ms], d[ms];

std::vector<int> qry(int x, int y) {
	std::vector<int> ans;
	x = std::upper_bound(all.begin(), all.end(), x) - all.begin();
	for(; x < ms; x += x & -x) {
		while(!tree[x].empty() && tree[x].back().first >= y) {
			ans.push_back(tree[x].back().second);
			tree[x].pop_back();
		}
	}
	return ans;
}

void setPoint(int x, int y, int i) {
	x = std::upper_bound(all.begin(), all.end(), x) - all.begin();
	for(; x > 0; x -= x & -x) {
		tree[x].emplace_back(y, i);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i] >> c[i] >> d[i];
		all.push_back(a[i]);
		all.push_back(c[i]);
	}
	all.push_back(0);
	std::sort(all.begin(), all.end());
	all.resize(std::unique(all.begin(), all.end()) - all.begin());
	setPoint(0, 0, 0);
	for(int i = 1; i <= n; i++) {
		setPoint(c[i], d[i], i);
	}
	for(int i = 0; i < ms; i++) {
		std::sort(tree[i].begin(), tree[i].end());
	}
	std::vector<int> to(n + 1, -1);
	std::queue<int> q;
	to[n] = n + 1;
	q.push(n);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		auto v = qry(a[on], b[on]);
		for(auto t : v) {
			if(to[t] == -1) {
				to[t] = on;
				q.push(t);
			}
		}
	}
	if(to[0] == -1) {
		std::cout << "-1\n";
		return 0;
	}
	std::vector<int> ans;
	for(int i = 0; i != n; ) {
		i = to[i];
		ans.push_back(i);
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}
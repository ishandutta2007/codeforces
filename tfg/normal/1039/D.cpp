#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int ms = 100100;
const int bs = 1000;

int n;

std::vector<int> edges[ms];
std::vector<std::pair<int, int>> trans;

void clean(int on, int par) {
	for(int i = 0; i < (int) edges[on].size(); i++) {
		if(edges[on][i] == par) {
			edges[on][i] = edges[on].back();
			edges[on].pop_back();
			i--;
			continue;
		}
		clean(edges[on][i], on);
		trans.emplace_back(on, edges[on][i]);
	}
}

std::pair<int, int> inter[ms];
int mx[ms];
bool got[ms];

int ans[ms];

int getAns(int x) {
	if(ans[x] == -1) {
		for(int i = 1; i <= n; i++) {
			inter[i] = std::pair<int, int>(0, 0);
			mx[i] = 0;
			got[i] = false;
		}
		for(auto e : trans) {
			int u = e.first, v = e.second;
			std::pair<int, int> nxt = inter[v];
			if(got[v]) {
				nxt.first++;
				nxt.second = 0;
			} else {
				nxt.second = mx[v] + 1;
			}
			if(mx[u] + nxt.second + 1 >= x) {
				got[u] = true;
			}
			if(mx[u] < nxt.second) {
				mx[u] = nxt.second;
			}
			inter[u].first += nxt.first;
		}
		if(got[1]) {
			inter[1].first++;
		}
		ans[x] = inter[1].first;
	}
	return ans[x];
}

void solve(int l, int r) {
	if(getAns(l) == getAns(r)) {
		return;
	}
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid + 1, r);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		ans[i] = -1;
	}
	ans[1] = n;
	for(int i = 1; i < n; i++) {
		int u, v;
		u = i, v = i + 1;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	clean(1, 0);
	solve(1, n);
	for(int i = n - 1; i > 0; i--) {
		ans[i] = std::max(ans[i], ans[i + 1]);
	}
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << std::endl;
	}
}
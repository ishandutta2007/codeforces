#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<std::pair<int, int>> edges[ms];
long long h[ms];
std::vector<long long> st;
long long a[ms];
int ans[ms];
int lul[ms];

void dfs(int on) {
	int he = (int) st.size();
	st.push_back(h[on]);
	lul[he] = 0;
	for(auto e : edges[on]) {
		h[e.first] = h[on] + e.second;
		dfs(e.first);
		lul[he] += lul[he+1];
	}
	int id = std::lower_bound(st.begin(), st.end(), h[on] - a[on]) - st.begin();
	id--;
	if(id >= 0) {
		lul[id]--;
	}
	lul[he]++;
	ans[on] = lul[he] - 1;
	st.pop_back();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int p, x;
		std::cin >> p >> x;
		edges[p-1].emplace_back(i, x);
	}
	dfs(0);
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << '\n';
	}
}
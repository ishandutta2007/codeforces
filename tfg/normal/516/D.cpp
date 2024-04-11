#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

const int ms = 200200;
const int MOD = 1e9 + 7;

long long dist[ms], cur_dist[ms];
int p[ms];
std::vector<std::pair<int, int>> edges[ms];

int dfs(int on, long long h = 0, int par = -1) {
	cur_dist[on] = h;
	int ans = on;
	dist[on] = std::max(dist[on], h);
	for(auto to : edges[on]) {
		if(to.first == par) continue;
		int cand = dfs(to.first, h + to.second, on);
		if(cur_dist[cand] > cur_dist[ans]) {
			ans = cand;
		}
	}
	return ans;
}

int in[ms], out[ms];
int c = 0;

int pre(int on, int par = -1) {
	in[on] = c++;
	for(auto to : edges[on]) {
		if(to.first == par) continue;
		pre(to.first, on);
	}
	out[on] = c;
}

int bit[ms];

void upd(int x, int v) {
	for(x++; x < ms; x += x & -x) {
		bit[x] += v;
	}
}

int qry(int x) {
	int ans = 0;
	for(x++; x > 0; x -= x & -x) {
		ans += bit[x];
	}
	return ans;
}

int qry(int l, int r) {
	return qry(r) - qry(l - 1);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
	}
	dfs(dfs(dfs(0)));
	int root = 0;
	for(int i = 0; i < n; i++) {
		if(dist[i] < dist[root]) {
			root = i;
		}
		//std::cout << dist[i] << (i + 1 == n ? '\n' : ' ');
	}
	pre(root);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::sort(p, p + n, [&](int a, int b) { return dist[a] != dist[b] ? dist[a] < dist[b] : in[a] < in[b]; });
	//std::sort(dist, dist + n);
	int m;
	std::cin >> m;
	while(m--) {
		long long L;
		std::cin >> L;
		int ans = 0;
		for(int l = 0, r = 0; l < n; l++) {
			while(r < n && dist[p[r]] - dist[p[l]] <= L) {
				upd(in[p[r++]], 1);
			}
			ans = std::max(ans, qry(in[p[l]], out[p[l]] - 1));
			upd(in[p[l]], -1);
		}
		std::cout << ans << std::endl;
	}
}
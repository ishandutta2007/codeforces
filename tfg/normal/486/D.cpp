#include <iostream>
#include <vector>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 2020;

std::vector<int> edges[ms], verts[ms];
ll size[ms];
bool del[ms];
int a[ms];

void dfs(int on, int limit, int par = -1) {
	//std::cout << "on " << on << ", got weight " << a[on] << " and limit " << limit << "\n";
	if(a[on] > limit) {
		//std::cout << "broke on " << on << "\n";
		size[on] = 0;
		return;
	}
	size[on] = 1;
	for(int i = 0; i < edges[on].size(); i++) {
		int to = edges[on][i];
		if(del[to]) {
			std::swap(edges[on][i], edges[on].back());
			edges[on].pop_back();
			i--;
			continue;
		}
		if(to != par) {
			dfs(to, limit, on);
			size[on] = (size[on] + size[on] * size[to]) % MOD;
		}
	}
}

ll to[ms];

int main() {
	to[0] = 1;
	for(int i = 1; i < ms; i++) {
		to[i] = to[i - 1] * 2 % MOD;
	}
	int n, d;
	std::cin >> d >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		verts[a[i]].push_back(i);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ll ans = 0;
	for(int i = 1; i < ms; i++) {
		for(auto on : verts[i]) {
			dfs(on, i + d);
			ans += size[on];
			//std::cout << "for " << on << ", got " << size[on] << "\n";
			del[on] = true;
		}
	}
	std::cout << ans % MOD << "\n";
}
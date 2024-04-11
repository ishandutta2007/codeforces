#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 200200;

/*int step[ms], cur_step = 1;
int size[ms], par[ms];

int getPar(int x) {
	if(step[x] != cur_step) {
		step[x] = cur_step;
		paths++;
		size[x] = 1;
		par[x] = x;
		//std::cout << "fixing " << x << std::endl;
	}
	if(x == par[x]) {
		return x;
	} else {
		return par[x] = getPar(par[x]);
	}
}

void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) {
		return;
	}
	if(size[a] < size[b]) {
		std::swap(a, b);
	}
	size[a] += size[b];
	par[b] = a;
}*/


int cap[ms];
std::vector<ii> edges[ms];
int used[2 * ms];
bool visit[ms];

int dfs(int on) {
	//std::cout << "on " << on << std::endl;
	visit[on] = true;
	int ans = cap[on];
	for(auto e : edges[on]) {
		if(visit[e.first]) {
			continue;
		}
		int need = dfs(e.first);
		used[e.second] -= need;
		ans += need;
	}
	//std::cout << "returning from " << on << " with " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> cap[i];
		sum += cap[i];
	}
	if(sum != 0) {
		std::cout << "Impossible\n";
		return 0;
	}
	int m;
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].emplace_back(v, 2 * i);
		edges[v].emplace_back(u, 2 * i + 1);
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		valid = valid && (visit[i] || dfs(i) == 0);
	}
	if(valid) {
		std::cout << "Possible\n";
		for(int i = 0; i < m; i++) {
			std::cout << -(used[2 * i] - used[2 * i + 1]) << std::endl;
		}
	} else {
		std::cout << "Impossible\n";
	}
}
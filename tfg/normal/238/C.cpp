#include <iostream>
#include <vector>
#include <string>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 3030;

std::vector<ii> edges[ms];
int down[ms], up[ms], upcost[ms], downcost[ms];

void dfs(int on, int par = -1) {
	down[on] = up[on] = upcost[on] = 0;
	for(auto e : edges[on]) {
		int to = e.first;
		if(to == par) continue;
		dfs(to, on);
		down[on] += down[to] + e.second;
		up[on] += up[to] + (1 - e.second);
	}
	upcost[on] = downcost[on] = up[on];
	for(auto e : edges[on]) {
		int to = e.first;
		if(to == par) continue;
		int restup = up[on] - (up[to] + 1 - e.second);
		upcost[on] = std::min(upcost[on], upcost[to] + restup + e.second);
		downcost[on] = std::min(downcost[on], downcost[to] + restup + 1 - e.second);
		downcost[on] = std::min(downcost[on], upcost[to] + restup);
	}
	//std::cout << "on " << on << " got up " << up[on] << ", down " << down[on] << ", upcost " << upcost[on] << std::endl;
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(ii(v, 1));
		edges[v].push_back(ii(u, 0));
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++) {
		//std::cout << "-------------\nSTARTING FROM " << i << std::endl;
		dfs(i);
		ans = std::min(ans, std::min(upcost[i], downcost[i]));
	}
	std::cout << ans << std::endl;
}
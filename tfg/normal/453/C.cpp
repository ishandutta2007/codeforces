#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 100100;

bool visit[ms];
std::vector<int> edges[ms];
int want[ms];
int cur[ms];
std::vector<int> ans;

void dfs(int on, int par = 0) {
	ans.push_back(on);
	visit[on] = true;
	cur[on] ^= 1;
	for(auto e : edges[on]) {
		if(visit[e]) {
			continue;
		}
		dfs(e, on);
	}
	if(cur[on] != want[on]) {
		if(par == 0) {
			if(edges[on].size() == 0) {
				return;
			}
			int to = edges[on][0];
			ans.push_back(to);
			cur[to] ^= 1;
			ans.push_back(on);
			cur[on] ^= 1;
			ans.push_back(to);
			cur[to] ^= 1;
		} else {
			ans.push_back(par);
			cur[par] ^= 1;
			ans.push_back(on);
			cur[on] ^= 1;
		}
	}
	if(par) {
		ans.push_back(par);
		cur[par] ^= 1;
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		//std::cin >> u >> v;
		scanf("%i %i", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int start = 0;
	for(int i = 1; i <= n; i++) {
		//std::cin >> want[i];
		scanf("%i", want + i);
		if(want[i]) {
			start = i;
		}
	}
	if(start == 0) {
		std::cout << "0\n\n";
	} else if(n == 1) {
		std::cout << "1\n1\n";
	} else {
		//std::cout << "starting from " << start << "\n";
		dfs(start);
		bool valid = true;
		for(int i = 1; i <= n; i++) {
			//std::cout << cur[i] << ' ';
			valid = valid && want[i] == cur[i];
		}
		//std::cout << '\n';
		if(!valid) {
			std::cout << "-1\n";
			return 0;
		}
		std::cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++) {
			//std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
			printf("%i%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
		}
	}
}
#include <iostream>
#include <queue>
#include <vector>

const int ms = 100100;

std::vector<int> edges[ms];
int degree[ms], co[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> co[i];
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		edges[v].push_back(u);
		degree[u]++;
	}
	std::queue<int> q[2];
	for(int i = 0; i < n; i++) {
		if(degree[i] == 0) {
			//std::cout << "pushing " << i << "\n";
			q[co[i]].push(i);
		}
	}
	int ans = 0;
	while(!q[0].empty() || !q[1].empty()) {
		if(!q[0].empty()) {
			int on = q[0].front();
			//std::cout << "got " << on << "\n";
			q[0].pop();
			for(auto to : edges[on]) {
				degree[to]--;
				if(degree[to] == 0) {
					//std::cout << "pushing " << to << "\n";
					q[co[to]].push(to);
				}
			}
		} else {
			while(!q[1].empty()) {
				int on = q[1].front();
				//std::cout << "got co " << on << "\n";
				q[1].pop();
				for(auto to : edges[on]) {
					degree[to]--;
					if(degree[to] == 0) {
						//std::cout << "pushing " << to << "\n";
						q[co[to]].push(to);
					}
				}
			}
			ans++;
		}
	}
	std::cout << ans << '\n';
}
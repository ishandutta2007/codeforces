#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

std::vector<int> dir[ms];
int in[ms], out[ms];
//std::vector<int> bi[ms];
bool visit[ms];

int bfs(int from, std::vector<int> edges[ms]) {
	std::queue<int> q;
	memset(visit, 0, sizeof visit);
	visit[from] = true;
	q.push(from);
	int ans = 0;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		ans++;
		for(auto to : edges[on]) {
			if(!visit[to]) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
	return ans;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		dir[u].push_back(v);
		in[v]++;
		out[u]++;
		//bi[u].push_back(v);bi[v].push_back(u);
	}
	/*if(bfs(1, bi) < n) {
		std::cout << "NO\n";
		return 0;
	}*/
	std::vector<int> srcs, sinks;
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			//std::cout << "adding " << i << " as source\n";
			srcs.push_back(i);
		}
		if(out[i] == 0) {
			//std::cout << "adding " << i << " as sink\n";
			sinks.push_back(i);
		}
	}
	std::sort(srcs.begin(), srcs.end());
	std::sort(sinks.begin(), sinks.end());
	int k = (int) srcs.size();
	std::vector<int> to(k, 0);
	for(int i = 0; i < k; i++) {
		bfs(srcs[i], dir);
		for(int j = 0; j < k; j++) {
			if(visit[sinks[j]]) {
				//std::cout << "from " << srcs[i] << " can visit " << sinks[j] << std::endl;
				to[i] |= 1 << j;
			}
		}
	}
	std::vector<int> near(1 << k, 0);
	std::vector<int> bits(1 << k, 0);
	for(int i = 0; i < (1 << k); i++) {
		for(int j = 0; j < k; j++) {
			if(i & (1 << j)) {
				near[i] |= to[j];
			}
		}
		bits[i] = i % 2 + bits[i / 2];
		//std::cout << "near " << i << " is " << near[i] << std::endl;
	}
	std::vector<bool> perfect(1 << k, true);
	for(int i = 1; i < (1 << k); i++) {
		if(bits[near[i]] < bits[i]) {
			perfect[i] = false;
			continue;
		}
		for(int j = 0; j < k; j++) {
			if((i & (1 << j)) != 0 && !perfect[i ^ (1 << j)]) {
				perfect[i] = false;
				break;
			}
		}
	}
	for(int i = 1; i + 1 < (1 << k); i++) {
		if(bits[i] >= bits[near[i]]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}
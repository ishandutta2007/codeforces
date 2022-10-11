#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

const int ms = 200200;

std::vector<int> edges[ms];
int seq[ms], inv[ms];
bool visit[ms];
int bfs[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		//std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", seq + i);
		inv[seq[i]] = i;
	}
	if(seq[0] != 1) {
		std::cout << "No\n";
		return 0;
	}
	int c = 0;
	std::queue<int> q;
	q.push(1);
	visit[1] = true;
	while(!q.empty()) {
		int on = q.front();
		bfs[c++] = on;
		q.pop();
		std::sort(edges[on].begin(), edges[on].end(), [&](int a, int b) { return inv[a] < inv[b]; });
		for(auto to : edges[on]) {
			if(!visit[to]) {
				q.push(to);
				visit[to] = true;
			}
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		valid = valid && seq[i] == bfs[i];
	}
	std::cout << (valid ? "Yes\n" : "No\n");
}
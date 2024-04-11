#include <iostream>
#include <vector>
#include <queue>

const int ms = 300300;
const int eps = 26;

int ans[ms][eps];
std::vector<int> edges[ms];
int degree[ms];

char str[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	scanf(" %s", str);
	while(m--) {
		int u, v;
		scanf("%i %i", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		degree[v]++;
	}
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		ans[i][str[i] - 'a'] = 1;
		if(degree[i] == 0) q.push(i);
	}
	int got = 0;
	int tot = 1;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		got++;
		for(auto e : edges[on]) {
			for(int j = 0; j < eps; j++) {
				ans[e][j] = std::max(ans[e][j], ans[on][j] + (j == str[e] - 'a' ? 1 : 0));
			}
			degree[e]--;
			if(degree[e] == 0) q.push(e);
		}
		for(int i = 0; i < eps; i++) {
			tot = std::max(tot, ans[on][i]);
		}
	}
	if(got != n) {
		std::cout << "-1\n";
	} else {
		std::cout << tot << '\n';
	}
}
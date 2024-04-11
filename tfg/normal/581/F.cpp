#include <iostream>
#include <vector>

const int ms = 5050;

std::vector<int> edges[ms];
int size[ms];
int dp[ms][ms][2];
int nxt[ms][2];

void dfs(int on, int par = -1) {
	dp[on][0][0] = dp[on][0][1] = 0;
	for(auto to : edges[on]) {
		if(to == par) continue;
		dfs(to, on);
		for(int i = 0; i <= size[on] + size[to]; i++) {
			nxt[i][0] = nxt[i][1] = 0x3f3f3f3f;
		}
		for(int i = 0; i <= size[on]; i++) {
			for(int j = 0; j <= size[to]; j++) {
				for(int k = 0; k < 2; k++) {
					for(int kk = 0; kk < 2; kk++) {
						nxt[i + j][k] = std::min(nxt[i + j][k], dp[on][i][k] + dp[to][j][kk] + (k ^ kk));
					}
				}
			}
		}
		for(int i = 0; i <= size[on] + size[to]; i++) {
			dp[on][i][0] = nxt[i][0];
			dp[on][i][1] = nxt[i][1];
		}
		size[on] += size[to];
	}
	if(size[on] == 0) {
		dp[on][1][0] = dp[on][0][1] = 0x3f3f3f3f;
		dp[on][0][0] = dp[on][1][1] = 0;
		size[on]++;
	}
	/*std::cout << "returning on " << on << std::endl;
	for(int i = 0; i <= size[on]; i++) {
		std::cout << dp[on][i][0] << (i == size[on] ? '\n' : ' ');
	}for(int i = 0; i <= size[on]; i++) {
		std::cout << dp[on][i][1] << (i == size[on] ? '\n' : ' ');
	}*/
}

int main() {
	int n;
	std::cin >> n;
	if(n == 2) {
		std::cout << "0\n";
		return 0;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int root;
	for(int i = 1; i <= n; i++) {
		if(edges[i].size() > 1) {
			root = i;
			break;
		}
	}
	dfs(root);
	std::cout << dp[root][size[root] / 2][0] << std::endl;
}
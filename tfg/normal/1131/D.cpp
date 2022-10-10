#include <iostream>
#include <vector>
#include <chrono>
#include <random>

const int ms = 1010;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[ms+ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	par[b] = a;
}

std::string mat[ms];
int deg[ms + ms];
int ans[ms + ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n+m; i++) {
		par[i] = i;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '<') {
				//deg[n+j]++;
			} else if(mat[i][j] == '>') {
				//deg[i]++;
			} else {
				makeUnion(i, j+n);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		//std::cin >> mat[i];
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '<') {
				deg[getPar(n+j)]++;
			} else if(mat[i][j] == '>') {
				deg[getPar(i)]++;
			} else {
				//makeUnion(i, j+n);
			}
		}
	}
	for(int rep = 1; 1; rep++) {
		std::vector<int> cur;
		for(int i = 0; i < n+m; i++) {
			if(deg[getPar(i)] == 0) {
				ans[i] = rep;
				cur.push_back(i);
			}
		}
		if(cur.empty()) break;
		for(auto v : cur) {
			deg[v] = -1;
			if(v < n) {
				for(int j = 0; j < m; j++) {
					if(mat[v][j] == '<') {
						deg[getPar(n+j)]--;
					}
				}
			} else {
				for(int i = 0; i < n; i++) {
					if(mat[i][v-n] == '>') {
						deg[getPar(i)]--;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '=' && ans[i] != ans[j+n]) {
				std::cout << "No\n";
				return 0;
			} else if(mat[i][j] == '>' && ans[i] <= ans[j+n]) {
				std::cout << "No\n";
				return 0;
			} else if(mat[i][j] == '<' && ans[i] >= ans[j+n]) {
				std::cout << "No\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < n+m; i++) {
		if(ans[i] == 0) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
	for(int i = 0; i < n+m; i++) {
		std::cout << ans[i] << (i + 1 == n || i + 1 == n + m ? '\n' : ' ');
	}
}
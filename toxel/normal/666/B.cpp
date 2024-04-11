#include<bits/stdc++.h>

const int N = 3010;
const int INF = 0x7f7f7f7f;

std::vector <int> e[N];
std::vector <std::pair <int, int>> maxto[N], maxarr[N];
int dis[N][N];
int n, m;
std::queue <int> q;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	memset(dis, 0x7f, sizeof(dis));
	for (int i = 1; i <= n; ++ i){
		while (!q.empty()){
			q.pop();
		}
		dis[i][i] = 0;
		q.push(i);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (auto v : e[u]){
				if (dis[i][v] == INF){
					dis[i][v] = dis[i][u] + 1;
					q.push(v);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (i == j){
				continue;
			}
			if (dis[i][j] < 100 * n){
				maxto[i].push_back({dis[i][j], j});
				maxarr[j].push_back({dis[i][j], i});
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		std::sort(maxarr[i].begin(), maxarr[i].end(), std::greater <std::pair <int, int>>());
		std::sort(maxto[i].begin(), maxto[i].end(), std::greater <std::pair <int, int>>());
		if ((int) maxarr[i].size() > 3){
			maxarr[i].erase(maxarr[i].begin() + 3, maxarr[i].end());
		}
		if ((int) maxto[i].size() > 3){
			maxto[i].erase(maxto[i].begin() + 3, maxto[i].end());
		}
	}
	int max = 0;
	std::pair <std::pair <int, int>, std::pair <int, int>> ans;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (i == j || dis[i][j] >= 100 * n){
				continue;
			}
			for (auto p1 : maxarr[i]){
				for (auto p2 : maxto[j]){
					if (p1.second != p2.second && p1.second != j && p2.second != i){
						int dist = p1.first + p2.first + dis[i][j];
						if (dist > max){
							max = dist;
							ans = {{p1.second, i}, {j, p2.second}};
							
						}
					}
				}
			}
		}
	}
	return printf("%d %d %d %d\n", ans.first.first, ans.first.second, ans.second.first, ans.second.second), 0;
}
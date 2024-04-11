#include<bits/stdc++.h>

const int N = 300010;
const int INF = 0x7f7f7f7f;

std::vector <int> e[N], _e[N];

int dis[N], pre[N];
bool vis[N];
int fa[N], sz[N];

int find(int u){
	if (u == fa[u]) return u;
	fa[u] = find(fa[u]);
	sz[u] = sz[fa[u]];
	return fa[u];
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v) return;
	fa[_u] = fa[_v];
	sz[_v] += sz[_u];
}

void bfs(int s, std::vector <int> *e){
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	std::queue <int> queue;
	queue.push(s);
	vis[s] = true;
	while (!queue.empty()){
		int u = queue.front();
		queue.pop();
		for (auto v : e[u]){
			if (!vis[v]){
				dis[v] = dis[u] + 1;
				pre[v] = u;
				queue.push(v);
				vis[v] = true;
			}
		}
	}
}

std::vector <int> path(int x){
	std::vector <int> ret;
	while (x != 1){
		ret.push_back(x);
		x = pre[x];
	}
	ret.push_back(1);
	std::reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		if (u == 1 || u == n || v == 1 || v == n) continue;
		_e[u].push_back(v);
		_e[v].push_back(u);
	}
	bfs(1, e);
	if (dis[n] <= 4){
		printf("%d\n", dis[n]);
		for (auto u : path(n)){
			printf("%d ", u);
		}
		putchar('\n');
		return 0;
	}
	for (int i = 2; i <= n - 1; ++ i){
		if (dis[i] == 2){
			std::vector <int> ans = path(i);
			ans.push_back(1);
			ans.push_back(n);
			printf("%d\n", (int) ans.size() - 1);
			for (auto u : ans){
				printf("%d ", u);
			}
			putchar('\n');
			return 0;
		}
	}
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
		sz[i] = 1;
	}
	for (int i = 2; i <= n - 1; ++ i){
		for (auto u : _e[i]){
			unite(u, i);
		}
	}
	for (int i = 2; i <= n - 1; ++ i){
		find(i);
		if (dis[i] != INF && _e[i].size() < sz[i] - 1){
			bfs(i, _e);
			for (int j = 2; j <= n - 1; ++ j){
				if (dis[j] == 2){
					std::vector <int> ret;
					int x = j;
					while (x != i){
						ret.push_back(x);
						x = pre[x];
					}
					ret.push_back(i);
					ret.push_back(1);
					std::reverse(ret.begin(), ret.end());
					ret.push_back(i);
					ret.push_back(n);
					printf("%d\n", (int) ret.size() - 1);
					for (auto u : ret){
						printf("%d ", u);
					}
					putchar('\n');
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}
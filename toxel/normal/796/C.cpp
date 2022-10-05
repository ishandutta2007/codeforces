#include<bits/stdc++.h>

const int N = 300010;

int a[N], fa[N];
int n, ans;
std::vector <int> e[N];
std::set <std::pair <int, int>> one, two, bro;
std::queue <int> q;

void bfs(int s){
	for (auto v : e[s]){
		one.insert({-a[v], v});
	}
	for (int i = 1; i <= n; ++ i){
		if (i != s && !one.count({-a[i], i})){
			two.insert({-a[i], i});
		}
	}
	int x = one.size() ? 1 - one.begin() -> first : INT_MIN;
	int y = two.size() ? 2 - two.begin() -> first : INT_MIN;
	ans = std::max(a[s], std::max(x, y));
	q.push(s);
	one.clear();
	while (!q.empty()){
		int u = q.front();
		q.pop();
		bro.clear();
		if (fa[u]){
			one.erase({-a[fa[u]], fa[u]});
			two.insert({-a[fa[u]], fa[u]});
		}
		two.erase({-a[u], u});
		one.insert({-a[u], u});
		for (auto v : e[u]){
			if (v == fa[u]){
				continue;
			}
			fa[v] = u;
			one.erase({-a[v], v});
			two.erase({-a[v], v});
			bro.insert({-a[v], v});
			q.push(v);
		}
		for (auto v : e[u]){
			if (v == fa[u]){
				continue;
			}
			bro.erase({-a[v], v});
			for (auto w : e[v]){
				if (w == fa[v]){
					continue;
				}
				two.erase({-a[w], w});
				one.insert({-a[w], w});
			}
			int x = one.size() ? 1 - one.begin() -> first : INT_MIN;
			int y = two.size() ? 2 - two.begin() -> first : INT_MIN;
			int z = bro.size() ? 2 - bro.begin() -> first : INT_MIN;
			ans = std::min(ans, std::max(std::max(x, y), std::max(z, a[v])));
			bro.insert({-a[v], v});
			for (auto w : e[v]){
				if (w == fa[v]){
					continue;
				}
				two.insert({-a[w], w});
				one.erase({-a[w], w});
			}
		}
		one.erase({-a[u], u});
		two.insert({-a[u], u});
		for (auto v : e[u]){
			if (v == fa[u]){
				continue;
			}
			two.insert({-a[v], v});
		}
	}
}

int main(){
	//freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs(1);
	return printf("%d\n", ans), 0;
}
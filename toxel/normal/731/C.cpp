#include<bits/stdc++.h>

const int N = 200010;

int fa[N], cnt[N], col[N];
std::vector <int> vec[N];

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v){
		return;
	}
	fa[_u] = fa[_v];
	find(_u);
}

int n, m, k;

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &col[i]);
	}
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		unite(u, v);
	}
	for (int i = 1; i <= n; ++ i){
		find(i);
		vec[fa[i]].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		if (!(int) vec[i].size()){
			continue;
		}
		for (auto u : vec[i]){
			++ cnt[col[u]];
		}
		int max = 0;
		for (auto u : vec[i]){
			max = std::max(cnt[col[u]], max);
			cnt[col[u]] = 0;
		}
		ans += (int) vec[i].size() - max;
	}
	return printf("%d\n", ans), 0;
}
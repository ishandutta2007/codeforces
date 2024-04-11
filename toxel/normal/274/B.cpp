#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::vector <int> e[N];
int n;
ll value[N];
std::pair <ll, ll> p[N];

void dfs(int u, int fa){
	for (auto v : e[u]){
		if (fa == v){
			continue;
		}
		dfs(v, u);
		p[u].first = std::max(p[u].first, p[v].first);
		p[u].second = std::max(p[u].second, p[v].second);
	}
	value[u] -= p[u].first - p[u].second;
	if (value[u] > 0){
		p[u].first += value[u];
	}
	else{
		p[u].second -= value[u];
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &value[i]);
	}
	dfs(1, 0);
	return printf("%I64d\n", p[1].first + p[1].second), 0;
}
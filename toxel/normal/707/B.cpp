#include<bits/stdc++.h>

const int N = 100010;

std::vector <std::pair <int, int>> e[N];
int n, m, k;
int a[N], dis[N];
bool exi[N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, u, v, w; i < m; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	if (!k){
		return printf("-1\n"), 0;
	}
	for (int i = 0; i < k; ++ i){
		scanf("%d", &a[i]);
		exi[a[i]] = true;
	}
	int ans = INT_MAX;
	for (int i = 1; i <= n; ++ i){
		if (exi[i]){
			continue;
		}
		int min = INT_MAX;
		for (auto u : e[i]){
			if (exi[u.first]){
				min = std::min(min, u.second);
			}
		}
		ans = std::min(ans, min);
	}
	return printf("%d\n", ans == INT_MAX ? -1 : ans), 0;
}
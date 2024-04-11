#include<bits/stdc++.h>

const int N = 10010;

int n, m, k, fa[N], c[N], sz[N];

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v){
		return;
	}
	fa[_u] = _v;
	find(u);
}

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		unite(u, v);
	}
	for (int i = 1; i <= n; ++ i){
		find(i);
		++ sz[fa[i]];
	}
	int max = 0, sit;
	for (int i = 0; i < k; ++ i){
		int x = sz[fa[c[i]]];
		if (x > max){
			max = x;
			sit = i;
		}
	}
	int ans = -m, sum = 0;
	for (int i = 0; i < k; ++ i){
		if (i == sit){
			continue;
		}
		int x = sz[fa[c[i]]];
		ans += x * (x - 1) >> 1;
		sum += x;
	}
	ans += (n - sum) * (n - sum - 1) >> 1;
	return printf("%d\n", ans), 0;
}
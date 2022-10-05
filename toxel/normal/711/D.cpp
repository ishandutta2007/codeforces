#include<bits/stdc++.h>

const int N = 200010;
const int moder = 1e9 + 7;

int fa[N], a[N], loop[N], sz[N], vis[N];
int n;

int find(int u){
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v){
		return;
	}
	fa[_u] = _v;
	find(u);
}

void dfs(int u, int dfn){
	vis[u] = dfn;
	if (vis[a[u]]){
		loop[fa[u]] = dfn - vis[a[u]] + 1;
		return;
	}
	dfs(a[u], dfn + 1);
}

int power_mod(int a, int exp){
	int ret = 1;
	while (exp){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
		exp >>= 1;
	}
	return ret;
}

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		unite(i, a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		find(i);
		if (vis[fa[i]]){
			continue;
		}
		dfs(fa[i], i);
	}
	for (int i = 1; i <= n; ++ i){
		++ sz[fa[i]];
	}
	int ans = 1;
	for (int i = 1; i <= n; ++ i){
		if (!sz[i]){
			continue;
		}
		ans = 1ll * ans * power_mod(2, sz[i] - loop[i]) % moder * (power_mod(2, loop[i]) - 2 + moder) % moder;
	}
	return printf("%d\n", ans), 0;
}
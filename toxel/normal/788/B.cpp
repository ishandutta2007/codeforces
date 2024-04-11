#include<bits/stdc++.h>

#define ll long long

const int N = 1000010;

int fa[N];
bool vis[N];

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

int n, m, cnt[N];

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	scanf("%d%d", &n, &m);
	int loop = 0;
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		vis[u] = vis[v] = true;
		if (u == v){
			++ loop;
			continue;
		}
		++ cnt[u], ++ cnt[v];
		unite(u, v);
	}
	int father = 0;
	for (int i = 1; i <= n; ++ i){
		find(i);
		if (!vis[i]){
			continue;
		}
		if (!father){
			father = fa[i];
		}
		if (fa[i] != father){
			return printf("0\n"), 0;
		}
	}
	ll ans = (1ll * loop * (loop - 1) >> 1) + 1ll * loop * (m - loop);
	for (int i = 1; i <= n; ++ i){
		ans += 1ll * cnt[i] * (cnt[i] - 1) >> 1;
	}
	return printf("%I64d\n", ans), 0;
}
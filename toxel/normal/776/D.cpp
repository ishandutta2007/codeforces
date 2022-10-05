#include<bits/stdc++.h>

const int N = 100010;

int fa[N << 1], a[N], n, m;
std::pair <int, int> p[N];

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	fa[_u] = _v;
	find(u);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < N << 1; ++ i){
		fa[i] = i;
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 1, x; i <= m; ++ i){
		scanf("%d", &x);
		for (int j = 0, y; j < x; ++ j){
			scanf("%d", &y);
			if (p[y].first){
				p[y].second = i;
			}
			else{
				p[y].first = i;
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (a[i]){
			if (find(p[i].first) == find(p[i].second + m)){
				return printf("NO\n"), 0;
			}
			unite(p[i].first, p[i].second);
			unite(p[i].first + m, p[i].second + m);
		}
		else{
			if (find(p[i].first) == find(p[i].second)){
				return printf("NO\n"), 0;
			}
			unite(p[i].first, p[i].second + m);
			unite(p[i].first + m, p[i].second);
		}
	}
	return printf("YES\n"), 0;
}
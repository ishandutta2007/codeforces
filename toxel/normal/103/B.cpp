#include<bits/stdc++.h>

const int N = 100010;

int fa[N];
int n, m;

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
	scanf("%d%d", &n, &m);
	if (n != m){
		return printf("NO\n"), 0;
	}
	for (int i = 1; i <= n; ++ i){
		fa[i] = i;
	}
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		unite(u, v);	
	}
	for (int i = 1; i <= n; ++ i){
		find(i);
		if (fa[i] != fa[1]){
			return printf("NO\n"), 0;
		}
	}
	return printf("FHTAGN!\n"), 0;
}
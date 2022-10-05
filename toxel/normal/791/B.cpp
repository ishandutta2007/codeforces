#include<bits/stdc++.h>

const int N = 150010;

int fa[N], pair[N][2], cnt1[N], cnt2[N];
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
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	for (int i = 0; i < m; ++ i){
		scanf("%d%d", &pair[i][0], &pair[i][1]);
		unite(pair[i][0], pair[i][1]);
	}
	for (int i = 1; i <= n; ++ i){
		find(i);
		++ cnt1[fa[i]];
	}
	for (int i = 0; i < m; ++ i){
		++ cnt2[fa[pair[i][0]]];
	}
	for (int i = 1; i <= n; ++ i){
		if (1ll * cnt1[i] * (cnt1[i] - 1) >> 1 != cnt2[i]){
			return printf("NO\n"), 0;
		}
	}
	return printf("YES\n"), 0;
}
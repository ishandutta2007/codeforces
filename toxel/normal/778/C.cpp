#include<bits/stdc++.h>

const int N = 300010;
const int M = 26;

int to[N][M], __to[N][M], sz[N], __sz[N], n, ans[N];
std::vector <int> rollback;

int merge(int u, int v){
	if (!u){
		return v;
	}
	if (!v){
		return u;
	}
	if (sz[u] < sz[v]){
		std::swap(u, v);
	}
	rollback.push_back(u);
	for (int i = 0; i < M; ++ i){
		int &x = to[u][i];
		int y = to[v][i];
		sz[u] -= sz[x];
		x = merge(x, y);
		sz[u] += sz[x];
	}
	return u;
}

void dfs(int i, int dep){
	sz[i] = 1;
	for (int j = 0; j < M; ++ j){
		int x = to[i][j];
		if (!x){
			continue;
		}
		dfs(x, dep + 1);
		sz[i] += sz[x];
	}
	__sz[i] = sz[i];
	int w = 0;
	for (int j = 0; j < M; ++ j){
		int x = to[i][j];
		if (!x){
			continue;
		}
		w = merge(w, x);
	}
	ans[dep] += w ? sz[i] - sz[w] : 0;
	for (auto u : rollback){
		sz[u] = __sz[u];
		memcpy(to[u], __to[u], sizeof(to[u]));
	}
	rollback.clear();
}

int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		getchar();
		char ch = getchar();
		to[u][ch - 'a'] = __to[u][ch - 'a'] = v;
	}
	dfs(1, 0);
	int max = 0, sit = 0;
	for (int i = 0; i < N; ++ i){
		if (max < ans[i]){
			max = ans[i];
			sit = i;
		}
	}
	return printf("%d\n%d\n", n - max, sit + 1), 0;
}
#include<bits/stdc++.h>

const int N = 1010;

char s[N][N];
int n, m, k;
int cnt[N][N];
int ans[N * N];
int fa[N * N];

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v) return;
	fa[_u] = _v;
}

int calc(int x, int y){
	return x * m + y;
}

int main(){
	for (int i = 0; i < N * N; ++ i) fa[i] = i;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == '*') continue;
			int sit = calc(i, j);
			if (i){
				if(s[i - 1][j] == '*') ++ cnt[i][j];
				else unite(sit, calc(i - 1, j));
			}
			if (i < n - 1){
				if(s[i + 1][j] == '*') ++ cnt[i][j];
				else unite(sit, calc(i + 1, j));
			}
			if (j){
				if(s[i][j - 1] == '*') ++ cnt[i][j];
				else unite(sit, calc(i, j - 1));
			}
			if (j < m - 1){
				if(s[i][j + 1] == '*') ++ cnt[i][j];
				else unite(sit, calc(i, j + 1));
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			int cal = calc(i, j);
			ans[find(cal)] += cnt[i][j];
		}
	}
	while (k --){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ans[fa[calc(x - 1, y - 1)]]);
	}
	return 0;
}
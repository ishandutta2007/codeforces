#include<bits/stdc++.h>

const int N = 100010;

int n, fa[N << 2], a[N], b[N];

int find(int n){
	return fa[n] == n ? n : fa[n] = find(fa[n]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	fa[_u] = _v;
}

int main(){
	scanf("%d", &n);
	bool flag = true;
	for (int i = 1; i <= n << 2; ++ i)
		fa[i] = i;
	for (int i = 1; i < n; ++ i){
		unite(2 * i, 2 * i + 1 + 2 * n);
		unite(2 * i + 2 * n, 2 * i + 1);
	}
	unite(2 * n, 2 * n + 1);
	unite(4 * n, 1);
	for (int i = 1; i <= n; ++ i){
		scanf("%d%d", &a[i], &b[i]);
		if (find(a[i]) == find(b[i])){
			flag = false;
			continue;
		}
		unite(a[i], b[i] + 2 * n);
		unite(a[i] + 2 * n, b[i]);
	}
	if (!flag)
		return printf("-1\n"), 0;
	for (int i = 1; i <= n << 2; ++ i){
		find(i);
	}
	for (int i = 1; i <= n; ++ i){
		int ans1 = fa[a[i]] <= 2 * n ? 1 : 2;
		printf("%d %d\n", ans1, 3 - ans1);
	}
	return 0;
}
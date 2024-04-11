#include<bits/stdc++.h>

const int N = 100010;

int fa[N];

int find(int u){
	return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	fa[_u] = _v;
	find(u);
}

int cnt[N];

bool check(int n){
	for ( ; n; n /= 10){
		int x = n % 10;
		if (x != 4 && x != 7){
			return false;
		}
	}
	return true;
}

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	int n;
	scanf("%d", &n);
	for (int i = 0, u, v, w; i < n - 1; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		if (!check(w)){
			unite(u, v);
		}
	}
	for (int i = 1; i <= n; ++ i){
		++ cnt[find(i)];
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++ i){
		if (fa[i] == i){
			ans += 1ll * cnt[i] * (n - cnt[i]) * (n - cnt[i] - 1);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
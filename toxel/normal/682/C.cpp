#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

struct edge{
	int next, to, w;
};

edge e[N << 1];
int first[N], a[N], e_cnt = 0, n;
bool del[N];

void addedge(int u, int v, int w){
	e[++ e_cnt] = {first[u], v, w};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u, w};
	first[v] = e_cnt;
}

std::set <ll> set = {0};

void dfs(int u, int fa, ll add){
	auto _u = set.upper_bound(a[u] - add);
	if (_u != set.end()){
		del[u] = true;
	}
	for (int i = first[u]; i; i = e[i].next){
		int v = e[i].to;
		if (v == fa){
			continue;
		}
		if (del[u]){
			del[v] = true;
		}
		set.insert(-add);
		dfs(v, u, add + e[i].w);
		set.erase(-add);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 2, v, x; i <= n; ++ i){
		scanf("%d%d", &v, &x);
		addedge(i, v, x);
	}
	dfs(1, 0, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		if (del[i]){
			++ ans;
		}
	}
	return printf("%d\n", ans), 0;
}
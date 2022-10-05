#include<bits/stdc++.h>
#define ll long long

const int N = 200010;

struct edge{
	int next, to;
};

edge e[N << 1];
int n, first[N], cnt = 0;
bool vis[N];
ll ans = -LLONG_MAX, _max[N], a[N];

void addedge(int u, int v){
	e[++ cnt] = {first[u], v};
	first[u] = cnt;
	e[++ cnt] = {first[v], u};
	first[v] = cnt;
}

void dfs(int i){
	ll sum = 0, max = -LLONG_MAX;
	vis[i] = true;
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (vis[x])
			continue;
		dfs(x);
		if (max != -LLONG_MAX)
			ans = std::max(ans, max + _max[x]);
		sum += a[x];
		max = std::max(max, _max[x]);
	}
	a[i] += sum;
	_max[i] = std::max(a[i], max);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%I64d", &a[i]);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1);
	if (ans == -LLONG_MAX){
		printf("Impossible\n");
		return 0;
	}
	printf("%I64d\n", ans);
	return 0;
}
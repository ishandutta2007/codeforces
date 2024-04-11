#include<bits/stdc++.h>

const int N = 200010;
const int moder = 1e9 + 7;

int v[N];
std::vector <int> e[N];
int sz[N], szz[2][N];
int dep[N];
int ans = 0;
typedef std::pair <int, int> pii;

void dfs(int u, int fa){
	sz[u] = 1;
	szz[0][u] = 1;
	for (auto v : e[u]){
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		for (int i = 0; i < 2; ++ i){
			szz[i ^ 1][u] += szz[i][v];
		}
	}
}

void solve(int u, int fa){
	std::vector <pii> vec;
	for (auto v : e[u]){
		if (v == fa) continue;
		solve(v, u);
		vec.push_back({szz[0][v], szz[1][v]});
	}
	pii p = {szz[0][1] - szz[dep[u] & 1 ? 1 : 0][u], szz[1][1] - szz[dep[u] & 1 ? 0 : 1][u]};
	if (!(dep[u] & 1)){
		std::swap(p.first, p.second);
	}
	vec.push_back(p);
	for (auto v : vec){
		ans = (ans + 1ll * (v.second - v.first) * (sz[1] - v.first - v.second) % moder * ::v[u]) % moder;
		ans += ans < 0 ? moder : 0;
	}
	ans = (ans + 1ll * v[u] * sz[1]) % moder;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &v[i]);
		v[i] = (v[i] + moder) % moder;
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	solve(1, 0);
	printf("%d\n", ans);
	return 0;
}
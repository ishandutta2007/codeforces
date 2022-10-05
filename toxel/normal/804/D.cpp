#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int fa[N], dis[N], max[N], left[N], right[N];
int n, m, q;
std::vector <int> vec[N], e[N];
std::vector <ll> pre[N];
std::map <std::pair <int, int>, double> Hash;

void dfs(int u, int fa){
	for (auto v : e[u]){
		if (fa == v){
			continue;
		}
		::fa[v] = ::fa[u];
		dfs(v, u);
	}
}

int dfs1(int u, int fa){
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		dis[v] = dis[u] + 1;
		dfs1(v, u);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i){
		if (!fa[i]){
			fa[i] = i;
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (fa[i] == i){
			dis[i] = 0;
			dfs1(i, 0);
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (dis[i] > max[fa[i]]){
			max[fa[i]] = dis[i];
			left[fa[i]] = i;
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (fa[i] == i){
			dis[left[i]] = 0;
			dfs1(left[i], 0);
		}
	}
	memset(max, 0, sizeof(max));
	for (int i = 1; i <= n; ++ i){
		if (dis[i] > max[fa[i]]){
			max[fa[i]] = dis[i];
			right[fa[i]] = i;
		}
	}
	memcpy(max, dis, sizeof(max));
	for (int i = 1; i <= n; ++ i){
		if (fa[i] == i){
			dis[right[i]] = 0;
			dfs1(right[i], 0);
		}
	}
	for (int i = 1; i <= n; ++ i){
		max[i] = std::max(max[i], dis[i]);
		vec[fa[i]].push_back(max[i]);
	}
	for (int i = 1; i <= n; ++ i){
		if (!(int) vec[i].size()){
			continue;
		}
		std::sort(vec[i].begin(), vec[i].end());
		pre[i].resize((int) vec[i].size());
		for (int sz = vec[i].size(), j = sz - 1; j >= 0; -- j){
			pre[i][j] = vec[i][j] + (j == sz - 1 ? 0 : pre[i][j + 1]);
		}
	}
	while (q --){
		int u, v;
		scanf("%d%d", &u, &v);
		u = fa[u], v = fa[v];
		if (u == v){
			printf("-1\n");
			continue;
		}
		if (Hash.count({u, v})){
			printf("%.10lf\n", Hash[{u, v}]);
			continue;
		}
		if ((int) vec[u].size() > (int) vec[v].size()){
			std::swap(u, v);
		}
		ll ans = 0, max = std::max(::max[left[u]], ::max[left[v]]);
		for (auto w : vec[u]){
			int sit = std::lower_bound(vec[v].begin(), vec[v].end(), max - w - 1) - vec[v].begin();
			ans += 1ll * sit * max;
			if (sit != (int) vec[v].size()){
				ans += pre[v][sit] + 1ll * (w + 1) * ((int) vec[v].size() - sit);
			}
		}
		printf("%.10lf\n", Hash[{u, v}] = Hash[{v, u}] = 1.0 * ans / (int) vec[u].size() / (int) vec[v].size());
	}
	return 0;
}
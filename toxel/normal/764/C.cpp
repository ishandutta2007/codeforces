#include<bits/stdc++.h>

const int N = 100010;

struct edge{
	int next, to;
};

edge e[N << 1];
int n, first[N], color[N], cnt[N], e_cnt = 0;
bool same[N];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}
	
void dfs(int i, int fa){
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		dfs(x, i);
		same[i] = same[i] && same[x] && color[i] == color[x];
	}
}

void solve(int i, int fa){
	std::map <int, int> Hash;
	bool flag = true;
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		if (!same[x]){
			flag = false;
			break;
		}
	}
	if (flag){
		printf("YES\n%d\n", i);
		exit(0);
	}
	if (i != 1 && color[i] != color[fa]){
		return;
	}
	flag = true;
	int orz = 0, sit = 0;
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		if (!same[x]){
			sit = x;
			++ orz;
		}
		Hash[color[x]] = x;
		++ cnt[color[x]];
		if (Hash.size() > 2 || orz > 1){
			flag = false;
			break;
		}
	}
	if (!flag){
		for (auto u = Hash.begin(); u != Hash.end(); ++ u){
			cnt[u -> first] = 0;
		}
		return;
	}
	if (!Hash.size()){
		return;
	}
	if (Hash.size() == 1){
		auto &u = cnt[(Hash.begin()) -> first];
		for (int j = first[i]; j; j = e[j].next){
			int x = e[j].to;
			if (x == fa){
				continue;
			}
			if ((color[x] == color[i] || u == 1) && (!orz || x == sit)){
				solve(x, i);
			}
		}
		u = 0;
	}
	for (auto u = Hash.begin(); u != Hash.end(); ++ u){
		auto v = Hash.begin();
		if (u == Hash.begin()){
			++ v;
		}
		if (cnt[u -> first] == 1){
			if ((color[i] == v -> first) && (!orz || u -> second == sit)){
				solve(u -> second, i);
			}
		}
	}
	for (auto u = Hash.begin(); u != Hash.end(); ++ u){
		cnt[u -> first] = 0;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &color[i]);
		same[i] = true;
	}
	dfs(1, 0);
	solve(1, 0);
	printf("NO\n");
	return 0;
}
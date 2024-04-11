#include<bits/stdc++.h>

const int N = 100010;

int dfn[N], low[N], fa[N];
std::vector <int> e[N];
int n, m, cnt;
bool flag[N], instack[N];
std::stack <int> stack;

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	if (_u == _v){
		return;
	}
	fa[_u] = _v;
	find(_u);
}

void dfs(int u){
	stack.push(u);
	instack[u] = true;
	dfn[u] = low[u] = ++ cnt;
	for (auto v : e[u]){
		if (!dfn[v]) dfs(v);
		if (instack[v]) low[u] = std::min(low[u], low[v]);
	}
	if (low[u] == dfn[u]){
		while (stack.top() != u){
			flag[find(u)] = true;
			instack[stack.top()] = false;
			stack.pop();
		}
		stack.pop();
		instack[u] = false;
	}
}

int main(){
	for (int i = 0; i < N; ++ i){
		fa[i] = i;
	}
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		unite(u, v);
	}
	for (int i = 1; i <= n; ++ i){
		if (!dfn[i]){
			dfs(i);
		}
	}
	int ans = n;
	for (int i = 1; i <= n; ++ i){
		if (!flag[find(i)]){
			-- ans;
			flag[fa[i]] = true;
		}
	}
	return printf("%d\n", ans), 0;
}
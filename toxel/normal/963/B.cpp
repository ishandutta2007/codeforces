#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
bool del[N];
int deg[N];

void dfs1(int u, int fa){
	if (del[u]) return;
	del[u] = true;
	printf("%d\n", u);
	for (auto v : e[u]){
		if (v == fa) continue;
		dfs1(v, u);
	}
}

void dfs(int u, int fa){
	for (auto v : e[u]){
		if (v == fa) continue;
		dfs(v, u);
	}
	if (!(deg[u] & 1)){
		-- deg[fa];
		dfs1(u, fa);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		if (x){
			e[x].push_back(i);
			e[i].push_back(x);
			++ deg[x];
			++ deg[i];
		}
	}
	if (!(n & 1)){
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs(1, 0);
}
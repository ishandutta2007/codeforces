#include<bits/stdc++.h>

const int N = 1000010;
struct edge{
	int next, to;
};

edge e[N << 1];
int n, first[N], root, size[N], e_cnt = 0, temp[N], sum, orz[N];

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int i, int fa){
	size[i] = temp[i];
	std::pair <int, int> ans = {0, 0};
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		dfs(x, i);
		size[i] += size[x];
		if (orz[x]){
			if (!ans.first){
				ans.first = orz[x];
				orz[i] = orz[x];
			}
			else{
				ans.second = orz[x];
				printf("%d %d\n", ans.first, ans.second);
				exit(0);
			}
		}
	}
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		if (orz[x] && size[i] == 2 * sum / 3 && i != root){
			printf("%d %d\n", orz[x], i);
			exit(0);
		}
	}
	if (size[i] == sum / 3){
		orz[i] = i;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d%d", &x, &temp[i]);
		sum += temp[i];
		if (!x){
			root = i;
			continue;
		}
		addedge(x, i);
	}
	if (sum % 3){
		return printf("-1\n"), 0;
	}
	dfs(root, 0);
	return printf("-1\n"), 0;
}
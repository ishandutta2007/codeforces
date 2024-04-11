#include<bits/stdc++.h>

const int N = 300010;

std::vector <int> e[N];
std::queue <std::pair <int, int>> q;
bool exi[N], vis[N];
int c[N], u[N], v[N];
int n, k, d;

void bfs(){
	while (!q.empty()){
		int u = q.front().first, col = q.front().second;
		q.pop();
		for (auto v : e[u]){
			if (vis[v]){
				continue;
			}
			vis[v] = true;
			c[v] = col;
			q.push({v, col});
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 0, x; i < k; ++ i){
		scanf("%d", &x);
		exi[x] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		if (exi[i]){
			++ cnt;
			c[i] = i;
			vis[i] = true;
			q.push({i, i});
		}
	}
	for (int i = 0; i < n - 1; ++ i){
		scanf("%d%d", &u[i], &v[i]);
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	bfs();
	printf("%d\n", cnt - 1);
	for (int i = 0; i < n - 1; ++ i){
		if (c[u[i]] != c[v[i]]){
			printf("%d ", i + 1);
		}
	}
	return printf("\n"), 0;
}
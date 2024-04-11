#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, m, a[N], b[N], c[N], du[N];

vector <int> G[N], id[N];

void dfs(int x, int f, int flg) {
	for(int i = 0; i < (int) G[x].size(); ++ i) {
		int V = G[x][i];
		if(V == f) continue;
		c[id[x][i]] = flg ^ 1;
		dfs(V, x, flg ^ 1);
	}
}

int main() {
	cin >> t;
	for(; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) du[i] = 0, G[i].clear(), id[i].clear();
		for(int i = 1; i < n; ++ i) {
			scanf("%d%d", &a[i], &b[i]);
			++ du[a[i]]; ++ du[b[i]];
			G[a[i]].push_back(b[i]);
			id[a[i]].push_back(i);
			G[b[i]].push_back(a[i]);
			id[b[i]].push_back(i);
		}
		bool ok = 1;
		for(int i = 1; i <= n; ++ i) {
			if(du[i] > 2){
				ok = 0;
			}
		}
		if(!ok) {
			puts("-1");
			continue;
		}
		
		for(int i = 1; i<= n; ++ i) {
			if(du[i] == 1) {
				dfs(i, 0, 2);
				break;
			}
		}
		for(int i = 1; i < n; ++ i) {
			printf("%d ", c[i]);
		}
		puts("");
	}
}
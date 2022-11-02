#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n, a[N][N];

int cnt = 0;
bool vis[N];

vector<int> ord;

void dfs(int u) {
	vis[u] = true;
	++cnt;
	for (int j = 0; j < n; ++j) {
		if (a[u][j] > 0 && !vis[j]) {
			dfs(j);
		}
	}
	ord.push_back(u);
}

void dfs_r(int u) {
	vis[u] = true;
	++cnt;
	for (int j = 0; j < n; ++j) {
		if (a[j][u] > 0 && !vis[j]) {
			dfs_r(j);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs(0);	
	if (cnt != n) {
		puts("NO");
		return 0;
	}
	int d = ord.back();	
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	dfs_r(d);
	if (cnt == n) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
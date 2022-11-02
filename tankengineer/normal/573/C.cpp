#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n;

vector<int> edge[N];

vector<int> ord;

int cnt[N][4], fa[N];

void dfs(int u) {
	ord.push_back(u);
	int d = min(4, (int)edge[u].size()) - 1;
	cnt[u][d] = 1;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa[u]) {
			continue;
		}
		fa[v] = u;
		dfs(v);
		for (int j = 0; j < 4; ++j) {
			cnt[u][j] += cnt[v][j];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0);
	for (int i = 0; i < n; ++i) {
		int u = ord[i], c = 0;
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (v == fa[u]) {
				int tmp[4] = {cnt[0][0] - cnt[u][0], cnt[0][1] - cnt[u][1], cnt[0][2] - cnt[u][2], cnt[0][3] - cnt[u][3]};
				if (edge[v].size() == 3) {
					--tmp[2];
				}
				c += tmp[2] || tmp[3];
			} else {
				if (!(cnt[v][2] + cnt[v][3] == 0 || (cnt[v][2] == 1 && cnt[v][3] == 0 && edge[v].size() == 3))) {
					++c;
				}
			}
		}
		if (edge[u].size() >= 3 && c > 2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
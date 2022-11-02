#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n, size[N];
vector<int> edge[N];
char ans[N];

void dfs_size(int i, int fa) {
	size[i] = 1;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (v == fa || ans[v] != '\0') {
			continue;
		}
		dfs_size(v, i);
		size[i] += size[v];
	}
}

int dfs_cen(int i, int fa, int n) {
	int mc = n - size[i], rem = -1;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (v == fa || ans[v] != '\0') {
			continue;
		}
		int tmp = dfs_cen(v, i, n);
		if (tmp != -1) {
			rem = tmp;
		}
		mc = max(mc, size[v]);
	}
	return mc <= n / 2 ? i : rem;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	char now = 'A' - 1;
	vector<int> t;
	t.push_back(0);
	while (t.size()) {
		++now;
		if (now > 'Z') {
			printf("Impossible!\n");
			return 0;
		}
		vector<int> v;
		for (int i = 0; i < (int)t.size(); ++i) {
			int u = t[i];
			dfs_size(u, -1);
			int w = dfs_cen(u, -1, size[u]);
			ans[w] = now;
			for (int j = 0; j < (int)edge[w].size(); ++j) {
				if (ans[edge[w][j]] == '\0') {
					v.push_back(edge[w][j]);
				}
			}
		}
		t = v;
	}
	for (int i = 0; i < n; ++i) {
		printf("%c%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
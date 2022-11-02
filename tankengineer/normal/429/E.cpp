#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

const int N = 100005 << 1;
int ans[N];
vector<int> edge[N];

bool vis[N];

void dfs(int u, int col) {
	vis[u] = true;
	if (~u & 1) {
		ans[u >> 1] = col;
	}
	for (int j = 0; j < (int)edge[u].size(); ++j) {
		int v = edge[u][j];
		if (!vis[v]) {
			dfs(v, col ^ 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	vector<pair<int, int> > point;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		++y;
		point.push_back(make_pair(x, i * 2));
		point.push_back(make_pair(y, i * 2 + 1));
		edge[i * 2].push_back(i * 2 + 1);
		edge[i * 2 + 1].push_back(i * 2);
	}
	sort(point.begin(), point.end());
	for (int i = 0; i + 1 < (int)point.size(); i += 2) {
		int u = point[i].second, v = point[i + 1].second;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0; i < n * 2; ++i) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
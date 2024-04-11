#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n, x, y;

int cnt;

vector<int> edge[N];

int dgr[N];

int fa[N], ccnt[N];

int bfs(int root) {
	vector<int> q;
	q.push_back(root);
	fa[root] = -1;
	for (int i = 0; i < (int)q.size(); ++i) {
		int u = q[i];
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];	
			if (v == fa[u]) {
				continue;
			}
			fa[v] = u;
			q.push_back(v);
		}
	}
	for (int i = (int)q.size() - 1; i > 0; --i) {
		int u = q[i], v = fa[u];
		if (ccnt[u] < 2) {
			ccnt[v] += 1;
		} else {
			cnt += ccnt[u] - 1;
		}
	}
	if (ccnt[root] < 2) {
		cnt += 1;
	} else {
		cnt += ccnt[root] - 1;
	}
	return 0;
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		++dgr[u], ++dgr[v];
	}
	long long ans = 0;
	if (n == 2) {
		ans = x;
	} else {
		if (x > y) {
			int d = *max_element(dgr, dgr + n);
			int a;
			if (d == n - 1) {
				a = 2;
			} else {
				a = 1;
			}
			ans = (a - 1) * x + (long long)((n - 1) - (a - 1)) * y;
		} else {
			int root = max_element(dgr, dgr + n) - dgr;
			fa[root] = -1;
			bfs(root);
			ans = (long long)(cnt - 1) * y + (long long)((n - 1) - (cnt - 1)) * x;
		}
	}
	cout << ans << endl;
	return 0;
}
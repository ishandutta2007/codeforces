#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500;
int n, m, out[N], in[N], loop[N];

vector<int> e[N];

int match[N], vis[N], stamp;

int find(int u) {
	if (vis[u] == stamp) {
		return 0;
	}
	vis[u] = stamp;
	for (int j = 0; j < (int)e[u].size(); ++j) {
		int v = e[u][j];
		if (match[v] == -1 || find(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int matching() {
	memset(match, -1, sizeof(match));
	int ret = 0;
	for (int i = 0; i < n - 1; ++i) {
		++stamp;
		ret += find(i);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	vector<pair<int, int> > edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edges.push_back(make_pair(u, v));
		if (u != v) {
			++out[u];
			++in[v];
		} else {
			loop[u] = true;
		}
	}
	int ans = n * n;
	for (int i = 0; i < n; ++i) {
		int tmp = m + 2 * n - 1 - 2 * out[i] - 2 * in[i] - 2 * loop[i];
		for (int j = 0; j < n; ++j) {
			e[j].clear();
		}
		for (int j = 0; j < m; ++j) {
			if (edges[j].first == i || edges[j].second == i) {
				continue;
			}
			int u = edges[j].first, v = edges[j].second;
			if (u > i) {
				--u;
			}
			if (v > i) {
				--v;
			}
			e[u].push_back(v);
		}
		int t = matching();
		tmp = tmp + n - 1 - 2 * t;
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
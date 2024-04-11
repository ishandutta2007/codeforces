#include<cmath>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000 + 1;

int n, m;
int x[N], y[N];

vector<pair<int, int> > edges[N];
vector<int> sum[N];

int size[N], fa[N];

void dfs(int u) {
	size[u] = 1;
	int f = -1;
	for (int j = 0; j < (int)edges[u].size(); ++j) {
		int v = edges[u][j].first;
		if (v == fa[u]) {
			f = j;
		} else if (size[v] == 0) {
			fa[v] = u;
			dfs(v);
			edges[u][j].second = -size[v];
			size[u] += size[v];
		}
	}
	if (f != -1) {
		edges[u][f].second = size[u];
	}
}

int center;

bool by_angle(pair<int, int> a, pair<int, int> b) {
	int i = a.first, j = b.first;
	double x1 = x[i] - x[center], x2 = x[j] - x[center],
		   y1 = y[i] - y[center], y2 = y[j] - y[center];
	return atan2(y1, x1) > atan2(y2, x2);
}

int leftmost;

bool checkdir(vector<int> a) {
	long long area = 0;
	a.push_back(*a.begin());
	for (int i = 0; i + 1 < (int)a.size(); ++i) {
		long long x1 = x[a[i]], y1 = y[a[i]], x2 = x[a[i + 1]], y2 = y[a[i + 1]];
		area += x1 * y2 - x2 * y1;
	}
	return area > 0;
}

map<int, int> mem[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edges[u].push_back(make_pair(v, 0));
		edges[v].push_back(make_pair(u, 0));
	}
	leftmost = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		if (x[i] < x[leftmost]) {
			leftmost = i;
		}
	}
	edges[n].push_back(make_pair(leftmost, 0));
	edges[leftmost].push_back(make_pair(n, 0));
	x[n] = x[leftmost] - 1, y[n] = y[leftmost];
	fa[n] = -1;
	dfs(n);
	for (int i = 0; i <= n; ++i) {
		center = i;
//cout << "center" << ' ' << i << endl;
		sort(edges[i].begin(), edges[i].end(), by_angle);
		sum[i].push_back(0);
		for (int j = 0; j < (int)edges[i].size(); ++j) {
//cout << j << ' ' << edges[i][j].first << ' ' << edges[i][j].second << endl;
int u = edges[i][j].first;
//cout << x[u] - x[i] << ' ' << y[u] - y[i] << endl;
			mem[i][edges[i][j].first] = j;
			sum[i].push_back(sum[i].back() + edges[i][j].second);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int m;
		vector<int> query;
		scanf("%d", &m);	
		for (int i = 0; i < m; ++i) {
			int u;
			scanf("%d", &u);
			query.push_back(--u);
		}
		if (checkdir(query)) {
			reverse(query.begin(), query.end());
		}
		query.push_back(query[0]);
		query.push_back(query[1]);
		int ans = 0;
		for (int i = 1; i + 1 < (int)query.size(); ++i) {
			int u = query[i]; 
			int a = mem[u][query[i - 1]], b = mem[u][query[i + 1]];
			if (a < b) {
				ans += sum[u][b] - sum[u][a + 1];
			} else {
				ans += sum[u].back() - sum[u][a + 1] + sum[u][b];
			}
//cout << i << ' ' << u << ' ' << a << ' ' << b << ' ' << ans << endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
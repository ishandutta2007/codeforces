#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>

const int N = 150000;
const int P = N * 9;
int n, m, type, top[P], ind[P], r[N], c[N], point[P], ans[N];
bool vis[P];
std::vector<std::pair<int, int> > pts;
std::priority_queue<int> pq;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int find(int a) {
	if (top[a] == a) return a;
	return top[a] = find(top[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) top[b] = a;
}

int locate(int x, int y) {
	int p = std::lower_bound(pts.begin(), pts.end(), std::make_pair(x, y)) - pts.begin();
	if (p == pts.size() || pts[p].first != x || pts[p].second != y) return -1;
	return p;
}

void add(int ind) {
	if (vis[ind]) return;
	merge(ind, 0);
	vis[ind] = 1;
	for (int i = 0; i < 8; ++i) {
		int to = locate(pts[ind].first + dx[i], pts[ind].second + dy[i]);
		if (to != -1) {
			if (point[to] == -1) {
				if (i & 1 ^ 1) add(to);
			} else pq.push(point[to]);
		}
	}
}

bool test(int ind) {
	bool v[8], p[8];
	int all = 0, g[8];
	bool vany = 0;
	for (int i = 0; i < 8; ++i) {
		int go = locate(r[ind] + dx[i], c[ind] + dy[i]);
		g[i] = go;
		v[i] = vis[go];
		p[i] = point[go] != -1;
		all += p[i];
		if (v[i] && i & 1 ^ 1) vany = 1;
		if (point[go] == -1) {
			assert(vis[go] == (find(0) == find(go)));
		} else assert(!vis[go]);
	}
	if (!vany) return 0;
	if (all > 1) {
		if (find(g[0]) == find(g[4]) && (p[1] + p[2] + p[3]) && (p[5] + p[6] + p[7])) return 0;
		if (find(g[2]) == find(g[6]) && (p[7] + p[0] + p[1]) && (p[3] + p[4] + p[5])) return 0;
		if (find(g[0]) == find(g[2]) && p[1]) return 0;
		if (find(g[2]) == find(g[4]) && p[3]) return 0;
		if (find(g[4]) == find(g[6]) && p[5]) return 0;
		if (find(g[6]) == find(g[0]) && p[7]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &type);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", r + i, c + i);
		r[i] = -r[i];
		c[i] = -c[i];
		pts.push_back(std::make_pair(r[i], c[i]));
		for (int j = 0; j < 8; ++j) pts.push_back(std::make_pair(r[i] + dx[j], c[i] + dy[j]));
	}
	std::sort(pts.begin(), pts.end());
	pts.resize(std::unique(pts.begin(), pts.end()) - pts.begin());
	m = pts.size();
	memset(point, -1, sizeof point);
	for (int i = 0; i < n; ++i) {
		ind[i] = locate(r[i], c[i]);
		point[ind[i]] = i;
	}
	for (int i = 0; i < P; ++i) top[i] = i;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 8; ++j) {
			int to = locate(r[i] + dx[j], c[i] + dy[j]);
			if (point[to] != -1) merge(i, point[to]);
		}
	}
	for (int i = 0; i < n; ++i) if (find(i) != find(0)) {
		printf("NO\n");
		return 0;
	}
	add(0);
	for (int i = 0; i < P; ++i) top[i] = i;
	for (int i = 0; i < m; ++i) if (point[i] == -1) {
		for (int j = 0; j < 8; j += 2) {
			int to = locate(pts[i].first + dx[j], pts[i].second + dy[j]);
			if (to != -1 && point[to] == -1) merge(to, i);
		}
	}
	if (point[0] != -1) return 1;
	int it = 0;
	while (!pq.empty()) {
		int p = pq.top();
		pq.pop();
		if (point[ind[p]] != -1 && test(p)) {
			ans[it++] = p;
			point[ind[p]] = -1;
			add(ind[p]);
		}
	}
	if (it != n) return 1;
	printf("YES\n");
	for (int i = n - 1; i >= 0; --i) printf("%d\n", ans[i] + 1);
	return 0;
}
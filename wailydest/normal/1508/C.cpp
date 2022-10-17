#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

struct edge {
	int to, w;
};

const int N = 5000;
const int NN = 200000;
int n, m, adj[N][N], mn[N];
bool u[NN];
std::vector<edge> g[NN];

struct dsu 
{
	dsu *p;
	dsu() {
		p = this;
	}
	dsu *find() {
		if (p == this) return this;
		return p = p->find();
	}
} d[NN];

bool unite(dsu *a, dsu *b) 
{
	a = a->find();
	b = b->find();
	if (a != b) {
		b->p = a;
		return true;
	}
	return false;
}

long long get() 
{
	memset(mn, 0x3f, 4 * n);
	memset(u, 0, n);
	long long ans = 0;
	int last = 0;
	u[0] = true;
	for (int i = 0; i < n; ++i) {
		int next = -1;
		for (int j = 0; j < n; ++j) if (!u[j]) {
			mn[j] = std::min(mn[j], adj[j][last]);
			if (next == -1 || mn[j] < mn[next]) next = j;
		}
		u[next] = true;
		ans += mn[next];
		last = next;
	}
	return ans;
}

int main() 
{
	scanf("%d%d", &n, &m);
	if ((long long)n * (n - 1) / 2 - m < n) {
		int x = 0;
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			adj[a - 1][b - 1] = adj[b - 1][a - 1] = w;
			x ^= w;
		}
		long long ans = ~((long long)1 << 63);
		for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
			if (!adj[i][j]) {
				adj[i][j] = adj[j][i] = x;
				ans = std::min(ans, get());
				adj[i][j] = adj[j][i] = 0;
			}
		}
		printf("%lld\n", ans);
	}
	else {
		std::vector<std::pair<int, std::pair<int, int> > > e;
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			--a;
			--b;
			g[a].push_back({b, w});
			g[b].push_back({a, w});
			e.push_back(std::make_pair(w, std::make_pair(a, b)));
		}
		std::sort(e.begin(), e.end());
		int all = -1;
		for (int i = 0; i < n; ++i) {
			if ((n - g[i].size()) * 2 >= n + 5) {
				if (all == -1) all = i;
				else unite(d + i, d + all);
			}
			else {
				memset(u, 0, n);
				for (int j = 0; j < (int)g[i].size(); ++j) u[g[i][j].to] = true;
				for (int j = 0; j < n; ++j) if (!u[j]) unite(d + i, d + j);
			}
		}
		long long ans = 0;
		for (int i = 0; i < m; ++i) ans += unite(d + e[i].second.first, d + e[i].second.second) * e[i].first;
		printf("%lld\n", ans);
	}
	return 0;
}
#include <cstdio>
#include <cassert>
#include <vector>

struct dsu {
	dsu *p;
	int size, res;
	void reset() {
		p = 0;
		size = 1;
		res = 0;
	}
	dsu *find() {
		if (p) return p = p->find();
		return this;
	}
};

void unite(dsu *a, dsu *b) 
{
	a = a->find();
	b = b->find();
	if (a != b) {
		if (a->size < b->size) std::swap(a, b);
		b->p = a;
		a->size += b->size;
	}
}

const int N = 200000;
int t, n, m;
std::vector<std::pair<int, int> > g[N];
dsu d[N << 1];

void add(int u, int v) 
{
	unite(d + u, d + v);
	unite(d + (u ^ 1), d + (v ^ 1));
}

void dfs(int v, int pr = -1) 
{
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].first != pr) {
		if (g[v][i].second != -1) {
			if (__builtin_popcount(g[v][i].second) & 1) add(g[v][i].first << 1, v << 1 | 1);
			else add(g[v][i].first << 1, v << 1);
		}
		dfs(g[v][i].first, v);
	}
}

void dfs1(int v, int pr = -1) 
{
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].first != pr) {
		printf("%d %d ", v + 1, g[v][i].first + 1);
		if (g[v][i].second != -1) printf("%d\n", g[v][i].second);
		else printf("%d\n", (int)(d[v << 1].find()->res != d[g[v][i].first << 1].find()->res));
		dfs1(g[v][i].first, v);
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			d[i << 1].reset();
			d[i << 1 | 1].reset();
		}
		for (int i = 1; i < n; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			--a;
			--b;
			g[a].push_back(std::make_pair(b, c));
			g[b].push_back(std::make_pair(a, c));
		}
		dfs(0);
		for (int i = 0; i < m; ++i) {
			int a, b, p;
			scanf("%d%d%d", &a, &b, &p);
			--a;
			--b;
			add(a << 1, b << 1 | p);
		}
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			if (d[i << 1].find() == d[i << 1 | 1].find()) ok = 0;
			else {
				if (d[i << 1].find()->res) d[i << 1 | 1].find()->res = !(d[i << 1].find()->res - 1) + 1;
				else if (d[i << 1 | 1].find()->res) d[i << 1].find()->res = !(d[i << 1 | 1].find()->res - 1) + 1;
				else {
					d[i << 1].find()->res = 1;
					d[i << 1 | 1].find()->res = 2;
				}
			}
		}
		if (ok) {
			printf("YES\n");
			dfs1(0);
		} else printf("NO\n");
	}
	return 0;
}
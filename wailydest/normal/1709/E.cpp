#include <cstdio>
#include <set>
#include <vector>

const int N = 200000;
int n, a[N], d[N], up[N];
std::vector<int> g[N];

std::set<int> *dfs(int v, int pr = -1) {
	up[v] ^= a[v];
	std::set<int> *cur = new std::set<int>;
	cur->insert(up[v]);
	bool inc = 0;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		up[g[v][i]] = up[v];
		std::set<int> *next = dfs(g[v][i], v);
		d[v] += d[g[v][i]];
		if (cur->size() < next->size()) std::swap(cur, next);
		for (std::set<int>::iterator it = next->begin(); !inc && it != next->end(); ++it) if (cur->count(*it ^ a[v])) inc = 1;
		for (std::set<int>::iterator it = next->begin(); !inc && it != next->end(); ++it) cur->insert(*it);
		next->clear();
	}
	if (inc) {
		cur->clear();
		++d[v];
	}
	return cur;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs(0);
	printf("%d\n", d[0]);
	return 0;
}
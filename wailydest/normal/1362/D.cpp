#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500000;
vector<int> g[N];
int n, m;
pair<int, int> a[N];
int nxt[N];

bool check() 
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) if (a[i].first == a[g[i][j]].first) return false;
	}
	return true;
}

int main() 
{
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	if (!check()) {
		printf("-1\n");
		return 0;
	}
	sort(a, a + n);
	fill(nxt, nxt + n, 1);
	bool ok = true;
	for (int i = 0; i < n && ok; ++i) {
		int v = a[i].second;
		if (nxt[v] != a[i].first) ok = false;
		for (int j = 0; j < g[v].size(); ++j) if (nxt[g[v][j]] == a[i].first) ++nxt[g[v][j]];
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) printf("%d ", a[i].second + 1);
	printf("\n");
	return 0;
}
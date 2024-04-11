#include <cstdio>
#include <utility>
#include <vector>

const int N = 100000;
int n, m;
std::vector<int> g[N];
int h[N], p[N];
bool ok;
int t;

std::pair<int, int> dfs(int v, int pr = -1) 
{
	std::pair<int, int> out;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		std::pair<int, int> t = dfs(g[v][i], v);
		if (!ok) return std::pair<int, int>();
		out.first += t.first;
		out.second += t.second;
	}
	if (ok) {
		std::pair<int, int> t;
		if (((long long)out.first + out.second + h[v] + p[v]) & 1) ok = false;
		t.first = ((long long)out.first + out.second + h[v] + p[v]) / 2;
		t.second = t.first - h[v];
		if (t.first + t.second - out.first - out.second != p[v] || h[v] != t.first - t.second) ok = false;
		if (t.first < 0 || t.second < 0 || out.second < t.second - p[v]) ok = false;
		return t;
	}
	return std::pair<int, int>();
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", p + i);
		for (int i = 0; i < n; ++i) scanf("%d", h + i);
		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		ok = true;
		dfs(0);
		if (ok) printf("YES\n");
		else printf("NO\n");
		for (int i = 0; i < n; ++i) g[i].clear();
	}
	return 0;
}
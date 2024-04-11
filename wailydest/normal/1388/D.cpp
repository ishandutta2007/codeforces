#include <cstdio>
#include <vector>
#include <utility>

const int N = 200000;
int t, n, p[N];
long long a[N];
std::vector<int> g[N];
long long ans;
bool nt[N];
std::pair<std::vector<int>, std::vector<int> > ord[N];

void dfs(int v) 
{
	for (int i = 0; i < (int)g[v].size(); ++i) {
		dfs(g[v][i]);
		a[v] += std::max(a[g[v][i]], (long long)0);
		if (a[g[v][i]] > 0) ord[v].first.push_back(g[v][i]);
		else ord[v].second.push_back(g[v][i]);
	}
	ans += a[v];
}

void out(int v) 
{
	for (int i = 0; i < (int)ord[v].first.size(); ++i) out(ord[v].first[i]);
	printf("%d ", v + 1);
	for (int i = 0; i < (int)ord[v].second.size(); ++i) out(ord[v].second[i]);
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		if (p[i] != -1) {
			--p[i];
			g[p[i]].push_back(i);
			nt[i] = true;
		}
	}
	for (int i = 0; i < n; ++i) if (!nt[i]) dfs(i);
	printf("%lld\n", ans);
	for (int i = 0; i < n; ++i) if (!nt[i]) out(i);
	printf("\n");
	return 0;
}
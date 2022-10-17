#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200000;
int g[N][2];
bool u[N];
int tp[N];
int ind = 0;
int dist[N];
vector<int> toerase;

void dfs(int v) 
{
	u[v] = true;
	if (g[v][0] != -1) {
		if (!u[g[v][0]]) dfs(g[v][0]);
		if (g[v][1] != -1 && !u[g[v][1]]) dfs(g[v][1]);
	}
	tp[ind++] = v;
}

void testcase() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) g[i][0] = g[i][1] = -1;
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		(g[a - 1][0] == -1 ? g[a - 1][0] : g[a - 1][1]) = b - 1;
	}
	ind = 0;
	for (int i = 0; i < n; ++i) if (!u[i]) dfs(i);
	reverse(tp, tp + n);
	for (int i = 0; i < n; ++i) {
		if (dist[tp[i]] == 2) toerase.push_back(tp[i]);
		else if (g[tp[i]][0] != -1) {
			dist[g[tp[i]][0]] = max(dist[tp[i]] + 1, dist[g[tp[i]][0]]);
			if (g[tp[i]][1] != -1) dist[g[tp[i]][1]] = max(dist[tp[i]] + 1, dist[g[tp[i]][1]]);
		}
	}
	printf("%d\n", toerase.size());
	for (int i = 0; i < (int)toerase.size(); ++i) printf("%d ", toerase[i] + 1);
	printf("\n");
	memset(u, 0, n * sizeof(*u));
	toerase.clear();
	memset(dist, 0, 4 * n);
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}
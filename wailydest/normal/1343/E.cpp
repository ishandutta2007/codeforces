#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

int n;
vector<vector<int> > g;

void bfs(int v, vector<int> &dist) 
{
	queue<int> q;
	dist[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) {
			if (!dist[g[v][i]]) {
				q.push(g[v][i]);
				dist[g[v][i]] = dist[v] + 1;
			}
		}
	}
}
int dist(vector<int> &d, int to) 
{
	return d[to];
}

void solve() 
{
	int m, a, b, c;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	g.resize(n);
	vector<int> dist_a(n), dist_b(n), dist_c(n);
	vector<int> p(m);
	for (int i = 0; i < m; ++i) scanf("%d", &p[i]);
	sort(p.begin(), p.end());
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	bfs(a - 1, dist_a);
	bfs(b - 1, dist_b);
	bfs(c - 1, dist_c);
	vector<long long> p_sum(m);
	p_sum[0] = p[0];
	for (int i = 1; i < m; ++i) p_sum[i] = p_sum[i - 1] + p[i];
	long long ans = ((long long)1 << 62) - 1 + ((long long)1 << 62);
	for (int i = 0; i < n; ++i) {
		int da = dist(dist_a, i) - 1, db = dist(dist_b, i) - 1, dc = dist(dist_c, i) - 1;
		if (da + db + dc <= m) ans = min(ans, (long long)(db > 0 ? p_sum[db - 1] : 0) + (da + db + dc > 0 ? p_sum[da + db + dc - 1] : 0));
	}
	printf("%lld\n", ans);
	g.clear();
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 200000;

int n, m, k;
vector<int> g[N];
pair<pair<int, int>, int> field[N];
int begin[N], end[N];
int sufmx[N];

void bfs(int start, int *dis) 
{
	queue<int> q;
	vector<bool> used(n);
	used[start] = true;
	dis[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) if (!used[g[v][i]]) {
			q.push(g[v][i]);
			used[g[v][i]] = true;
			dis[g[v][i]] = dis[v] + 1;
		}
	}
}

int main() 
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &field[i].second);
		--field[i].second;
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	bfs(0, ::begin);
	bfs(n - 1, ::end);
	for (int i = 0; i < k; ++i) {
		field[i].first.first = ::begin[field[i].second];
		field[i].first.second = ::end[field[i].second];
	}
	sort(field, field + k);
	sufmx[k - 1] = 0;
	for (int i = k - 2; i >= 0; --i) sufmx[i] = max(sufmx[i + 1], field[i + 1].first.second);
	int path = 0;
	for (int i = 0; i < k - 1; ++i) path = max(path, sufmx[i] + field[i].first.first);
	printf("%d\n", min(path + 1, ::begin[n - 1]));
	return 0;
}
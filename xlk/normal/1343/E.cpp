#include <bits/stdc++.h>
using namespace std;
int t, n, m, A, B, C;
vector<int> a[200020];
queue<int> q;
int d1[200020];
int d2[200020];
int d3[200020];
long long s[200020];
void bfs(int d[], int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = -1;
	}
	d[s] = 0;
	q.push(s);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < a[u].size(); i++) {
			int e = a[u][i];
			if (d[e] == -1) {
				d[e] = d[u] + 1;
				q.push(e);
			}
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d%d%d%d", &n, &m, &A, &B, &C);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lld", &s[i]);
		}
		sort(s + 1, s + m + 1);
		for (int i = 1; i <= m; i++) {
			s[i] += s[i - 1];
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		bfs(d1, A);
		bfs(d2, B);
		bfs(d3, C);
		long long ans = 1e18;
		for (int i = 1; i <= n; i++) {
			if (d1[i] + d2[i] + d3[i] <= m) {
				ans = min(ans, s[d2[i]] + s[d1[i] + d2[i] + d3[i]]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
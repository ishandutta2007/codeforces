#include <cstdio>
#include <queue>

const int N = 300005;
int n, a[N], b[N], dist[N], prev[N], pprev[N];

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", b + i);
	std::queue<int> q;
	q.push(n);
	dist[n] = 1;
	int until = n - 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (!v) {
			printf("%d\n", dist[v] - 1);
			std::vector<int> v;
			int cur = 0;
			while (cur != n) {
				v.push_back(pprev[cur]);
				cur = prev[cur];
			}
			for (int i = (int)v.size() - 1; i >= 0; --i) printf("%d ", v[i]);
			printf("\n");
			return 0;
		}
		while (v - a[v] <= until) {
			int to = until + b[until];
			if (!dist[to]) {
				dist[to] = dist[v] + 1;
				prev[to] = v;
				pprev[to] = until;
				q.push(to);
			}
			--until;
		}
	}
	printf("-1\n");
	return 0;
}
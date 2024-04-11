#include <cstdio>
#include <queue>
#include <vector>

const int N = 200000;
int n, m, deg[N];
bool u[N];
std::vector<int> t[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		++deg[a];
		t[b].push_back(a);
	}
	std::priority_queue<std::pair<int, int> > pq;
	pq.push(std::make_pair(0, n - 1));
	while (!pq.empty()) {
		int v = pq.top().second, d = pq.top().first;
		pq.pop();
		if (!v) {
			printf("%d\n", -d);
			return 0;
		}
		if (!u[v]) {
			u[v] = 1;
			for (int i = 0; i < (int)t[v].size(); ++i) {
				--deg[t[v][i]];
				pq.push(std::make_pair(d - 1 - deg[t[v][i]], t[v][i]));
			}
		}
	}
	return 1;
}
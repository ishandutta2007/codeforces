#include <cstdio>
#include <utility>
#include <queue>

struct state {
	long long val;
	int v, k;
};

bool operator<(state a, state b) {
	return a.val > b.val;
}

const int N = 200000;
int n, m;
std::vector<std::pair<int, int> > g[N];
long long ans[N];
bool u[N][4];

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		g[a].push_back(std::make_pair(b, c));
		g[b].push_back(std::make_pair(a, c));
	}
	std::priority_queue<state> pq;
	pq.push({0, 0, 0});
	pq.push({0, 0, 3});
	while (!pq.empty()) {
		state cur = pq.top();
		pq.pop();
		if (!u[cur.v][cur.k]) {
			u[cur.v][cur.k] = true;
			if (cur.k == 3) ans[cur.v] = cur.val;
			for (int i = 0; i < (int)g[cur.v].size(); ++i) {
				if (cur.k == 0) {
					pq.push({cur.val + g[cur.v][i].second, g[cur.v][i].first, 0});
					pq.push({cur.val + 2 * g[cur.v][i].second, g[cur.v][i].first, 1});
					pq.push({cur.val, g[cur.v][i].first, 2});
				}
				if (cur.k == 1) {
					pq.push({cur.val, g[cur.v][i].first, 3});
					pq.push({cur.val + g[cur.v][i].second, g[cur.v][i].first, 1});
				}
				if (cur.k == 2) {
					pq.push({cur.val + 2 * g[cur.v][i].second, g[cur.v][i].first, 3});
					pq.push({cur.val + g[cur.v][i].second, g[cur.v][i].first, 2});
				}
				if (cur.k == 3) pq.push({cur.val + g[cur.v][i].second, g[cur.v][i].first, 3});
			}
		}
	}
	for (int i = 1; i < n; ++i) printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}
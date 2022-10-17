#include <cstdio>
#include <utility>
#include <queue>

const int N = 100005;
const int K = 505;
int t, n, k, r1[N], c1[N], r2[N], c2[N], cost[2][K][K];
bool u[K][K];

int co0(int x, int y) 
{
	return cost[0][x][y] + cost[0][k - x - 1][k - y];
}

int co1(int x, int y) 
{
	return cost[1][x][y] + cost[1][k - x][k - y - 1];
}

int calc() 
{
	for (int i = 0; i <= k; ++i) for (int j = 0; j <= k; ++j) {
		cost[0][i][j] = cost[1][i][j] = 0;
		u[i][j] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (r1[i] == r2[i]) ++cost[0][r1[i]][std::max(c1[i], c2[i])];
		else ++cost[1][std::max(r1[i], r2[i])][c1[i]];
	}
	std::priority_queue<std::pair<int, std::pair<int, int> > > pq;
	pq.push(std::make_pair(0, std::make_pair(k / 2, k / 2)));
	while (!pq.empty()) {
		std::pair<int, std::pair<int, int> > cur = pq.top();
		pq.pop();
		if (!cur.second.first || !cur.second.second || std::max(cur.second.first, cur.second.second) == k) return n + cur.first;
		int x = cur.second.first, y = cur.second.second;
		if (!u[x][y]) {
			u[x][y] = 1;
			if (x > 0) pq.push({cur.first - co0(x - 1, y), {x - 1, y}});
			if (x + 1 <= k) pq.push({cur.first - co0(x, y), {x + 1, y}});
			if (y > 0) pq.push({cur.first - co1(x, y - 1), {x, y - 1}});
			if (y + 1 <= k) pq.push({cur.first - co1(x, y), {x, y + 1}});
		}
	}
	return 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", r1 + i, c1 + i, r2 + i, c2 + i);
			--r1[i];
			--c1[i];
			--r2[i];
			--c2[i];
		}
		printf("%d\n", calc());
	}
	return 0;
}
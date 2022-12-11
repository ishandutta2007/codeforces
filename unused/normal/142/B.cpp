#include <bits/stdc++.h>
using namespace std;

int ptr[2];
int idx[1005][1005];

struct BipartiteMatching {
	int n, m;
	vector<vector<int>> graph;
	vector<int> matched, match, edgeview, level;
	vector<int> reached[2];
	BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1),
		match(n, -1) {}
	bool assignLevel() {
		bool reachable = false;
		level.assign(n, -1);
		reached[0].assign(n, 0);
		reached[1].assign(m, 0);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (match[i] == -1) {
				level[i] = 0;
				reached[0][i] = 1;
				q.push(i);
			}
		}
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto adj : graph[cur]) {
				reached[1][adj] = 1;
				auto next = matched[adj];
				if (next == -1) {
					reachable = true;
				}
				else if (level[next] == -1) {
					level[next] = level[cur] + 1;
					reached[0][next] = 1;
					q.push(next);
				}
			}
		}
		return reachable;
	}
	int findpath(int nod) {
		for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && level[next] != level[nod] + 1) continue;
			if (next == -1 || findpath(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return 1;
			}
		}
		return 0;
	}
	int solve() {
		int ans = 0;
		while (assignLevel()) {
			edgeview.assign(n, 0);
			for (int i = 0; i < n; i++)
				if (match[i] == -1)
					ans += findpath(i);
		}
		return ans;
	}
};

int dr[8][2] =
{
	2,-1,2,1,-2,1,-2,-1,
	1,2,1,-2,-1,2,-1,-2
};

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	if (n <= 100 || m <= 100)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				idx[i][j] = ptr[(i + j) & 1]++;
			}
		}

		BipartiteMatching bm{ ptr[0], ptr[1] };

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i + j) & 1) continue;
				for (int k = 0; k < 8; k++)
				{
					int nx = i + dr[k][0], ny = j + dr[k][1];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					bm.graph[idx[i][j]].push_back(idx[nx][ny]);
				}
			}
		}

		printf("%d\n", n * m - bm.solve());
	}
	else
	{
		printf("%d\n", (n * m + 1) / 2);
	}
}
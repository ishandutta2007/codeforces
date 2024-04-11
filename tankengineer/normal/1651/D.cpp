#include<cassert>
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 200005 * 5, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int n, m;

int x[N], y[N];

map<pair<int, int>, int> mem;

int dis[N], bestx[N], besty[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		mem[make_pair(x[i], y[i])] = i;
		dis[i] = -1;
	}
	m = n;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		for (int d = 0; d < 4; ++d) {
			int tx = x[i] + dx[d], ty = y[i] + dy[d];
			if (!mem.count(make_pair(tx, ty))) {
				x[m] = tx, y[m] = ty, mem[make_pair(tx, ty)] = m;
				dis[m] = 0, bestx[m] = tx, besty[m] = ty;
				q.push(m);
				++m;
			}
		}
	}
	while (q.size()) {
		int i = q.front();
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int tx = x[i] + dx[d], ty = y[i] + dy[d];
			if (mem.count(make_pair(tx, ty))) {
				int j = mem[make_pair(tx, ty)];
				if (dis[j] == -1) {
					dis[j] = dis[i] + 1;
					bestx[j] = bestx[i];
					besty[j] = besty[i];
					q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", bestx[i], besty[i]);
	}
	return 0;
}
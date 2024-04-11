#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>
#include <unordered_map>

using namespace std;

const int maxn = 3010;

vector <int> ed[maxn];
int dst[maxn][maxn];
int n;

void go(int v) {
	for (int i = 1; i <= n; i++) {
		dst[v][i] = n + 1;
	}

	dst[v][v] = 0;

	queue <int> q;

	q.push(v);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < (int)ed[u].size(); i++) {
			int x = ed[u][i];

			if (dst[v][x] == n + 1) {
				dst[v][x] = dst[v][u] + 1;
				q.push(x);
			}
		}
	}
}

int main() {
	int m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		go(i);
	}

	int s1, t1, l1, s2, t2, l2;

	scanf("%d %d %d %d %d %d", &s1, &t1, &l1, &s2, &t2, &l2);

	if (dst[s1][t1] > l1 || dst[s2][t2] > l2) {
		printf("-1");
		return 0;
	}

	int ans = dst[s1][t1] + dst[s2][t2];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = dst[i][j];
			int y = dst[s1][i] + dst[j][t1] + x;
			int z = min(dst[s2][i] + dst[j][t2], dst[s2][j] + dst[i][t2]) + x;

			if (y <= l1 && z <= l2) {
				ans = min(ans, y + z - x);
			}
		}
	}

	cout << m - ans << endl;

	return 0;
}
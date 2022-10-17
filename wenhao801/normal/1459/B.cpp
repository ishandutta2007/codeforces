#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

#include <queue>
using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair<int, int>
int to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct pt { int x, y, t, las; };
queue <pt> q;
int ans[10];
map <pii, bool> vis[10];

int main () {
	int x = read();
	if (x & 1) {
		++x; x >>= 1; cout << x * (x + 1) * 2 << endl;
	}
	else {
		x >>= 1; ++x; cout << x * x << endl;
	}
	return 0;
	q.push({0, 0, 0, 999});
	while (!q.empty()) {
		pt x = q.front(); q.pop();
		if (x.t == 9) break;
		if (!vis[x.t][make_pair(x.x, x.y)]) ++ans[x.t], vis[x.t][make_pair(x.x, x.y)] = 1, printf("%d | %d %d\n", x.t, x.x, x.y);
		for (int i = 0; i < 4; i++) {
			if (i == x.las || i == (x.las ^ 1)) continue;
			int tx = x.x + to[i][0], ty = x.y + to[i][1];
			q.push({tx, ty, x.t + 1, i});
		}
	}
	for (int i = 1; i <= 9; i++) cout << ans[i] << ' ';
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

priority_queue <int> q;
int a[200200] = {};

int main () {
	int T = read();
	while (T--) {
		int n = read();
		int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		int ans = 0;
		for (i = 1; i <= n; i++) if (a[i] % 2 == 0) q.push(a[i]);
		int las = 0;
		while (!q.empty()) {
			int f = q.top();
			q.pop();
			if (las == f) continue;
			if (f % 2 == 1) continue;
			q.push(f / 2);
			ans++;
			las = f;
		}
		printf("%d\n", ans);
	}
	return 0;
}
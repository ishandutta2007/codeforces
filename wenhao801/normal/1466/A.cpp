#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
int a[55];
bool vis[55];

int main () {
	int T = read();
	while (T--) {
		int n = read(), ans = 0;
		int i, j;
		for (i = 1; i <= 50; i++) vis[i] = 0;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) {
			if (a[j] - a[i] > 0 && !vis[a[j] - a[i]]) vis[a[j] - a[i]] = 1, ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
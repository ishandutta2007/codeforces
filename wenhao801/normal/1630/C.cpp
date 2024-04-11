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

const int MAXN = 200200;
int n, a[MAXN], r[MAXN], tmp[MAXN];

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = n; i >= 1; i--) {
		r[i] = tmp[a[i]];
		if (!tmp[a[i]]) tmp[a[i]] = i;
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		if (!r[i]) continue;
		ans += r[i] - i - 1;
		int mx = i, last = r[i];
		for (j = i + 1; j < r[i]; j++) if (r[j] > r[mx]) mx = j;
		while (r[mx] > last) {
			ans += r[mx] - last - 1; int tr = r[mx];
			for (j = last + 1; j < tr; j++) if (r[j] > r[mx]) mx = j;
			last = tr;
		}
		i = last;
	}
	printf("%d\n", ans);
	return 0;
}
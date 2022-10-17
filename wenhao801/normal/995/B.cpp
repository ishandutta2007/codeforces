#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 202;
int a[MAXN];

int main () {
	int n = read(), i, j;
	for (i = 1; i <= 2 * n; i++) {
		a[i] = read();
	}
	int ans = 0;
	for (i = 1; i <= 2 * n; i += 2) {
		if (a[i] != a[i + 1]) {
			for (j = i + 2; j <= 2 * n; j++) if (a[i] == a[j]) break;
			while (j != i + 1) swap(a[j], a[j - 1]), ++ans, --j;
		}
	}
	cout << ans;
	return 0;
}
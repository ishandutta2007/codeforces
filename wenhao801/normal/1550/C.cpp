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

int n, a[200200];
bool check (int l, int r) {
	for (int i = l + 1; i <= r; i++) for (int j = i + 1; j <= r; j++)
		if ((a[i] >= a[l] && a[j] >= a[i]) || (a[i] <= a[l] && a[j] <= a[i]))
			return 0;
	return 1;
}

int main () {
	// freopen("test.in", "r", stdin);
	int T = read();
	while (T--) {
		n = read(); int i, j; long long ans = 0;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i++) {
			if (i <= 2) { ans += i; continue; }
			ans += 2;
			for (j = i - 2; j >= 1; j--) if (check(j, i)) { ++ans; } else break;
		}
		cout << ans << endl;
	}
	return 0;
}
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

int a[110];
int main () {
	int T = read();
	while (T--) {
		int n = read(), k = read(), i;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i < n; i++) {
			int now = min(k, a[i]);
			k -= now; a[i] -= now; a[n] += now;
		}
		for (i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
	}
	return 0;
}
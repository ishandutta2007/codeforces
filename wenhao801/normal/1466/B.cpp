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
int buc[200200];
int main () {
	int T = read();
	while (T--) {
		int n = read(), i, j;
		for (i = 1; i <= 2 * n + 1; i++) buc[i] = 0;
		for (i = 1; i <= n; i++) {
			int x = read(); ++buc[x];
		}
		int ans =0 ;
		for (i = 1; i <= 2 *n + 1; i++) {
			if (buc[i]) ++ans, --buc[i];
			if (buc[i]) ++buc[i + 1];
		}
		printf("%d\n", ans);
	}
	return 0;
}
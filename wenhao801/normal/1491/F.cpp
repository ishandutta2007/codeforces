#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n;

int ask (int l1, int r1, int l2, int r2) {
	printf("? %d %d\n", r1 - l1 + 1, r2 - l2 + 1);
	for (int i = l1; i <= r1; i++) printf("%d ", i); putchar('\n');
	for (int i = l2; i <= r2; i++) printf("%d ", i); putchar('\n');
	fflush(stdout); int res = read(); return res;
}

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j; vector <int> ans;
		for (i = 2; i <= n; i++) {
			int res = ask(1, i - 1, i, i);
			if (res) {
				for (j = i + 1; j <= n; j++) if (!ask(i, i, j, j)) ans.push_back(j);
				int L = 1, R = i - 1;
				while (L < R) {
					int mid = (L + R) >> 1;
					if (ask(L, mid, i, i)) R = mid;
					else L = mid + 1;
				}
				for (j = 1; j < i; j++) if (j != L) ans.push_back(j);
				break;
			}
		}
		printf("! %d", ans.size()); for (auto i: ans) printf(" %d", i); putchar('\n'); fflush(stdout);
	}
	return 0;
}
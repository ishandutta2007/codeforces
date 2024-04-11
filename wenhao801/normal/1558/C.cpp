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

int n, a[2200];
vector <int> ans;
void add (int x) { ans.push_back(x); reverse(a + 1, a + x + 1); }

int main () {
	int T = read();
	while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		for (i = 1; i <= n; i += 2) if (a[i] % 2 == 0) break;
		if (i != n + 2) { puts("-1"); continue; }
		for (i = 2; i <= n; i += 2) if (a[i] & 1) break;
		if (i != n + 1) { puts("-1"); continue; }
		ans.clear();
		while (n != 1) {
			int mx1 = 0, mx2 = 0;
			for (i = 1; i <= n; i++) {
				if (a[i] == n) mx1 = i;
				if (a[i] == n - 1) mx2 = i;
			}
			mx2 = (mx2 > mx1 ? mx2 : (mx1 - mx2 + 1)); add(mx1); mx1 = 1;
			add(mx2 - 1); add(mx2 + 1); add(3); add(n);
			n -= 2;
		}
		printf("%d\n", ans.size());
		for (auto i: ans) printf("%d ", i);
		puts("");
	}
	return 0;
}
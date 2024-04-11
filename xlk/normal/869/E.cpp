#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> g;
int c[2520][2520], n, m, q;
void R(int x, int y, int z) {
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= m; j += j & -j) {
			c[i][j] ^= z;
		}
	}
}
int G(int x, int y) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			re ^= c[i][j];
		}
	}
	return re;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; i++) {
		int o, xa, ya, xb, yb;
		scanf("%d%d%d%d%d", &o, &xa, &ya, &xb, &yb);
		if (o == 3) {
			puts(G(xa, ya) == G(xb, yb) ? "Yes" : "No");
		} else {
			int &u = g[{xa, xb, ya, yb}];
			if (u == 0) {
				u = rand() << 15 | rand();
			}
			R(xa, ya, u);
			R(xa, yb + 1, u);
			R(xb + 1, ya, u);
			R(xb + 1, yb + 1, u);
		}
	}
	return 0;
}
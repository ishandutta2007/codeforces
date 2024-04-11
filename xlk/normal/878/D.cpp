#include <bits/stdc++.h>
using namespace std;
int a[12][100000];
bitset<1 << 12>h[100020];
int n, m, q, o, x, y, c;
using namespace std;
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
		for (int j = 0; j < 1 << 12; j++) {
			if (j >> i & 1) {
				h[i][j] = 1;
			}
		}
	}
	c = m;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &o, &x, &y);
		x--;
		y--;
		if (o == 1) {
			h[c++] = h[x] | h[y];
		} else if (o == 2) {
			h[c++] = h[x] & h[y];
		} else {
			vector<pair<int, int> >v;
			for (int i = 0; i < m; i++) {
				v.push_back(make_pair(a[i][y], i));
			}
			sort(v.begin(), v.end());
			int mask = 0;
			for (int i = m - 1; i >= 0; i--) {
				mask |= 1 << v[i].second;
				if (h[x][mask]) {
					printf("%d\n", v[i].first);
					break;
				}
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[300020];
int p[300020];
int n;
vector<pair<int, int> > z;
void gao(int x, int y) {
	assert(abs(x - y) >= n / 2);
	if (x == y) {
		return;
	}
	z.push_back(make_pair(x, y));
	swap(a[x], a[y]);
	p[a[x]] = x;
	p[a[y]] = y;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	for (int i = 2; i < n; i++) {
		if (a[i] != i) {
			if (i <= n / 2) {
				if (p[i] <= n / 2) {
					gao(p[i], n);
					gao(n, i);
				} else {
					gao(p[i], 1);
					gao(1, n);
					gao(n, i);
				}
			} else {
				if (p[i] > n / 2) {
					gao(p[i], 1);
					gao(1, i);
				} else {
					gao(p[i], n);
					gao(n, 1);
					gao(1, i);
				}
			}
		}
	}
	if (a[1] != 1) {
		gao(1, n);
	}
	for (int i = 1; i <= n; i++) {
		assert(a[i] == i);
	}
	printf("%d\n", (int)z.size());
	for (int i = 0; i < z.size(); i++) {
		printf("%d %d\n", z[i].first, z[i].second);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[300020];
vector<int> z;
int n, m;
int d[300020], s, c;
bool v[300020];
void dfs(int x, int y) {
	v[x] = true;
	for (pair<int, int> u: a[x]) {
		if (u.first == y) {
			continue;
		}
		if (v[u.first]) {
			continue;
		}
		dfs(u.first, x);
		if (d[u.first]) {
			d[u.first] ^= 1;
			d[x] ^= 1;
			z.push_back(u.second);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		if (d[i] == 1) {
			s++;
		}
		if (d[i] == -1) {
			c++;
		}
	}
	if (c == 0 && s % 2 == 1) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == -1) {
			d[i] = s % 2;
			s += d[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	dfs(1, 0);
	printf("%d\n", (int)z.size());
	for (int i = 0; i < (int)z.size(); i++) {
		printf("%d\n", z[i]);
	}
	return 0;
}
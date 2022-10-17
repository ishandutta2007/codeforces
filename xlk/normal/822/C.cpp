#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<pair<int, int> > L[200020];
vector<pair<int, int> > R[200020];
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		L[l].push_back(make_pair(r - l + 1, c));
		R[r].push_back(make_pair(r - l + 1, c));
	}
	int z = 2147483647;
	map<int, int> g;
	for (int i = 1; i <= 200000; i++) {
		for (pair<int, int> j: L[i]) {
			if (g.count(j.first)) {
				z = min(z, g[j.first] + j.second);
			}
		}
		for (pair<int, int> j: R[i]) {
			if (g.count(x - j.first)) {
				g[x - j.first] = min(g[x - j.first], j.second);
			} else {
				g[x - j.first] = j.second;
			}
		}
	}
	if (z == 2147483647) {
		z = -1;
	}
	printf("%d\n", z);
	return 0;
}
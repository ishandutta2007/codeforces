#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long> > a[200020];
int n, m;
long long d[200020];
set<pair<long long, int> > s;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		long long z;
		scanf("%d%d%lld", &x, &y, &z);
		a[x].push_back(make_pair(y, z * 2));
		a[y].push_back(make_pair(x, z * 2));
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		s.insert(make_pair(d[i], i));
	}
	while (s.size()) {
		int u = s.begin() -> second;
		s.erase(s.begin());
		for (int i = 0; i < a[u].size(); i++) {
			if (d[a[u][i].first] > d[u] + a[u][i].second) {
				s.erase(make_pair(d[a[u][i].first], a[u][i].first));
				d[a[u][i].first] = d[u] + a[u][i].second;
				s.insert(make_pair(d[a[u][i].first], a[u][i].first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}
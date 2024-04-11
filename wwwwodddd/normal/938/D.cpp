#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long> > a[200020];
long long d[200020], z;
int n, m, x, y;
void add(int x, int y, long long z) {
	a[x].push_back(make_pair(y, z));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%lld", &x, &y, &z);
		add(x, y, 2 * z);
		add(y, x, 2 * z);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &z);
		add(0, i, z);
	}
	memset(d, 0x3f, sizeof d);
	d[0] = 0;
	set<pair<long long, int> > s;
	s.insert(make_pair(0LL, 0));
	while (s.size()) {
		pair<long long, int> u = *s.begin();
		s.erase(s.begin());
		for (auto i: a[u.second]) {
			if (d[i.first] > d[u.second] + i.second) {
				s.erase(make_pair(d[i.first], i.first));
				d[i.first] = d[u.second] + i.second;
				s.insert(make_pair(d[i.first], i.first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld%c", d[i], i == n ? '\n' : ' ');
	}
}
#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int maxn = (int)1e5 + 10;

pair <pair <int, int>, int> v[maxn];

struct point {
	int l;
	int r;
	int cnt;
	int num;
};

bool operator <(point a, point b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}

	if (a.r != b.r) {
		return a.r < b.r;
	}

	return a.num < b.num;
}

point t[maxn];
int ans[maxn];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first.first, &v[i].first.second);
		v[i].second = i;
	}

	sort(v, v + n);

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t[i].l, &t[i].r, &t[i].cnt);
		t[i].num = i + 1;
	}

	sort(t, t + m);

	int pos = 0;

	set <pair <pair <int, int>, int> > s;

	for (int i = 0; i < n; i++) {
		while (pos < m && t[pos].l <= v[i].first.first) {
			s.insert(make_pair(make_pair(t[pos].r, t[pos].cnt), t[pos].num));
			pos++;
		}

		if (s.empty()) {
			printf("NO");
			return 0;
		}

		set <pair <pair <int, int>, int> >::iterator it = s.lower_bound(make_pair(make_pair(v[i].first.second, -1), -1));

		if (it == s.end()) {
			printf("NO");
			return 0;
		}

		ans[v[i].second] = ((*it).second);

		pair <pair <int, int>, int> f = (*it);

		s.erase(f);

		f.first.second--;

		if (f.first.second != 0) {
			s.insert(f);
		}
	}

	printf("YES\n");

	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
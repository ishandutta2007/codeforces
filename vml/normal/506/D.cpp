#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = (int)1e5 + 10;

vector <pair <int, int> > ed[maxn];
vector <int> v[maxn];
set <int> s[maxn];

int p[maxn];
vector <pair <int, int> > cl[maxn];

int get_parent(int v) {
	if (p[v] == v) {
		return v;
	}

	p[v] = get_parent(p[v]);

	return p[v];
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int x, y, c;

		scanf("%d %d %d", &x, &y, &c);

		ed[c].push_back(make_pair(x, y));
		if (!s[c].count(x)) {
			v[c].push_back(x);
			s[c].insert(x);
		}
		if (!s[c].count(y)) {
			v[c].push_back(y);
			s[c].insert(y);
		}
	}

	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			p[v[i][j]] = v[i][j];
		}

		for (int j = 0; j < (int)ed[i].size(); j++) {
			int x = ed[i][j].first;
			int y = ed[i][j].second;

			x = get_parent(x);
			y = get_parent(y);

			if (x != y) {
				p[x] = y;
			}
		}

		for (int j = 0; j < (int)v[i].size(); j++) {
			cl[v[i][j]].push_back(make_pair(i, get_parent(v[i][j])));
		}
	}

	int q;

	map <pair <int, int>, int> f;

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		if (cl[x].size() > cl[y].size()) {
			swap(x, y);
		}

		if (f.count(make_pair(x, y))) {
			printf("%d\n", f[make_pair(x, y)]);
			continue;
		}

		int ans = 0;

		if (cl[x].size() + cl[y].size() < cl[x].size() * log((double)cl[y].size()) / log(2.0)) {
			int pos1 = 0, pos2 = 0;

			while (pos1 < (int)cl[x].size() && pos2 < (int)cl[y].size()) {
				if (cl[x][pos1] == cl[y][pos2]) {
					ans++;
				}

				if (cl[x][pos1].first < cl[y][pos2].first) {
					pos1++;
				} else {
					pos2++;
				}
			}
		} else {
			for (int j = 0; j < (int)cl[x].size(); j++) {
				int l = 0;
				int r = (int)cl[y].size() - 1;

				if (r < l) {
					break;
				}

				while (l != r) {
					int m = (l + r) >> 1;

					if (cl[y][m].first < cl[x][j].first) {
						l = m + 1;
					} else {
						r = m;
					}
				}

				if (cl[x][j] == cl[y][l]) {
					ans++;
				}
			}
		}

		printf("%d\n", ans);

		f[make_pair(x, y)] = ans;
	}

	return 0;
}
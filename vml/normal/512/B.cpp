#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

const int maxn = 310;

pair <int, int> v[maxn];

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}

	return gcd(y, x % y);
}

map <pair <int, int>, int> m;
int n;

int go(int pos, int g) {
	if (!m.count(make_pair(pos, g))) {
		if (pos == n) {
			if (g == 1) {
				m[make_pair(pos, g)] = 0;
			} else {
				m[make_pair(pos, g)] = (int)1e9;
			}
		} else {
			m[make_pair(pos, g)] = min(go(pos + 1, g), v[pos].second + go(pos + 1, gcd(g, v[pos].first)));
		}
	}

	return m[make_pair(pos, g)];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].first);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].second);
	}

	int ans = go(0, 0);

	if (ans == (int)1e9) {
		printf("-1");
	} else {
		printf("%d", ans);
	}

	return 0;
}
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 1000000000 + 1;

int n, k, s, t;

vector<pair<int, int> > cars;

vector<int> pos;

int calc(int c) {
	int ret = 0;
	for (int i = 0; i < (int)pos.size(); ++i) {
		if (c >= pos[i] * 2) {
			ret += pos[i];
		} else {
			ret += pos[i] * 2 - c + pos[i];
		}
	}
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 0; i < n; ++i) {
		int c, v;
		scanf("%d%d", &c, &v);
		cars.push_back(make_pair(v, c));
	}
	for (int i = 0; i < k; ++i) {
		int g;
		scanf("%d", &g);
		pos.push_back(g);
	}
	pos.push_back(s);
	sort(pos.begin(), pos.end());
	for (int i = k; i > 0; --i) {
		pos[i] -= pos[i - 1];
	}
	sort(pos.begin(), pos.end());
	int l = *pos.rbegin(), maxc = 2 * l + 1, r = maxc;
	while (l < r) {
		int m = ((r - l) >> 1) + l;
		if (calc(m) <= t) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	int minc = l;
	if (minc == maxc) {
		printf("-1\n");
	} else {
		int minv = INF;
		for (int i = 0; i < n; ++i) {
			if (cars[i].first >= minc) {
				minv = min(minv, cars[i].second);
			}
		}
		if (minv == INF) {
			printf("-1\n");
		} else {
			printf("%d\n", minv);
		}
	}
	return 0;
}
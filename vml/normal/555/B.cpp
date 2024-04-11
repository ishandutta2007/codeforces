#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int maxn = (int)2e5 + 10;

struct segm {
	long long l, r;
	int num;
};

segm v[maxn];

bool operator <(segm a, segm b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}

	return a.r < b.r;
}

int ans[maxn];

int main() {
	long long l, r;

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		long long l1, r1;

		scanf("%I64d %I64d", &l1, &r1);

		if (i != 0) {
			v[i - 1].l = l1 - r;
			v[i - 1].r = r1 - l;
			v[i - 1].num = i;
		}

		l = l1;
		r = r1;
	}

	n--;

	sort(v, v + n);

	vector <pair <long long, int> > a;

	for (int i = 0; i < m; i++) {
		long long x;

		scanf("%I64d", &x);

		a.push_back(make_pair(x, i + 1));
	}

	sort(a.begin(), a.end());
	int pos = 0;

	set <pair <long long, int> > s;

	for (int i = 0; i < m; i++) {
		while (pos < n && v[pos].l <= a[i].first) {
			s.insert(make_pair(v[pos].r, v[pos].num));
			pos++;
		}

		while (!s.empty() && (*s.begin()).first < a[i].first) {
			printf("No");
			return 0;
		}

		if (s.empty()) {
			continue;
		}

		ans[(*s.begin()).second] = a[i].second;

		s.erase(s.begin());
	}

	if (pos != n || !s.empty()) {
		printf("No");
		return 0;
	}

	printf("Yes\n");

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}
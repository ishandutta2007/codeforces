#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 150005;
int a[N], b[N], g[N], mins[N << 1], tag[N << 1];

int getID(const int l, const int r) {
	return l + r | l != r;
}

void update(const int l, const int r) {
	int k = l + r >> 1;
	mins[getID(l, r)] = min(mins[getID(l, k)], mins[getID(k + 1, r)]);
}


void segChange(const int l, const int r, const int a, const int b, const int delta) ;

void pushdown(const int l, const int r) {
	int x = getID(l, r);
	if (tag[x]) {
		int k = l + r >> 1;
		segChange(l, k, l, r, tag[x]);
		segChange(k + 1, r, l, r, tag[x]);
		tag[x] = 0;
	}
}

void segChange(const int l, const int r, const int a, const int b, const int delta) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		tag[getID(l, r)] += delta;
		mins[getID(l, r)] += delta;
		return;
	}
	int k = l + r >> 1;
	pushdown(l, r);
	segChange(l, k, a, b, delta);
	segChange(k + 1, r, a, b, delta);
	update(l, r);
}

int main() {
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}
	sort(b, b + m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		int t1 = lower_bound(b, b + m, h - a[i]) - b;
		g[i] = m - t1;
	}
	for (int i = 1; i <= m; ++i) {
		segChange(0, m, i, m, 1);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		segChange(0, m, g[i], m, -1);
		if (i >= m - 1) {
			if (mins[getID(0, m)] >= 0) {
				++ans;
			}
			segChange(0, m, g[i - m + 1], m, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> t[500000];
int x[500000], y[500000], z[500000], f[500001], p[500001];

bool myless (int i, int j) {
	return z[i] > z[j] || z[i] == z[j] && y[i] > y[j];
}

int add (int x, int p) {
	for (; x <= 500000; x = x | (x + 1)) f[x] = max (f[x], p);
}

int get (int x) {
	int p = 0;
	for (; x > 0 ; x = (x & (x + 1)) - 1) p = max (f[x], p);
	return p;
}

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &y[i]);
		t[i] = make_pair (-y[i], i);
	}
	for (int i = 0; i < n; i++) scanf ("%d", &z[i]);
	sort (t, t + n);
	int r = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && t[i - 1].first != t[i].first) r++;
		y[t[i].second] = r;
	}
	sort (p, p + n, myless);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += int (get (y[p[i]] - 1) > x[p[i]]);                         
		add (y[p[i]], x[p[i]]);
	}
	printf ("%d\n", ans);
	return 0;
}
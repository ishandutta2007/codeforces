#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn], b[maxn];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	function<bool(double)> check = [&](double p) {
		for (int i = 0; i < n; ++i) {
			double x = (m + p) / a[i];
			if (x > p + 1e-9) return false;
			p -= x;
			x = (m + p) / (b[(i + 1) % n]);
			if (x > p + 1e-9) return false;
			p -= x;
		}
		return true;
	};
	double l = 0.0, r = 1e10;
	for (int t = 0; t < 200; ++t) {
		double m = (l + r) / 2.0;
		if (check(m)) r = m;
		else l = m;
	}
	if (r > 1e9) puts("-1");
	else printf("%.20lf\n", l);
	return 0;
}
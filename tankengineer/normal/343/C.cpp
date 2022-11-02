#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, M = 100005;
int n, m;
long long h[N], a[M];

bool check(long long t) {
	int uncheck = 0;
	for (int i = 0; i < n; ++i) {
		if (uncheck == m) {
			continue;
		}
		long long p = a[uncheck], l, r;
		if (p < h[i] - t) {
			continue;
		}
		if (p <= h[i]) {
			l = p, r = max(h[i], max(h[i] + ((t - (h[i] - p)) >> 1), p + (t - (h[i] - p))));
		} else {
			l = h[i], r = h[i] + t;
		}
		while (uncheck < m && a[uncheck] >= l && a[uncheck] <= r) {
			++uncheck;
		}
	}
	return uncheck == m;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	if (check(0)) {
		cout << 0 << endl;
		return 0;
	}
	long long l = 0, r = 100000000000, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}
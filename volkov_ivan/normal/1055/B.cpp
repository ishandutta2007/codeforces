#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 7;
long long a[MAX_N], pa[MAX_N];

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	long long x, n, m;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pa[i] = -1;
	}
	int ans = 0, l = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			if (l != -1) {
				pa[l] = i - 1;
				pa[i - 1] = l;
				l = -1;
				ans++;
			}
		} else {
			if (l == -1) l = i;
		}
	}
	if (l != -1) {
		pa[n] = l;
		ans++;
		pa[l] = n;
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << ans << "\n";
		} else {
			long long p, d;
			cin >> p >> d;
			if (a[p] > x) {
				a[p] += d;
				continue;
			}
			if (a[p] + d <= x) {
				a[p] += d;
				continue;
			}
			a[p] += d;
			if (p == 1) {
				if (p + 1 <= n && a[p + 1] > x) {
					pa[pa[p + 1]] = p;
					pa[p] = pa[p + 1];
				} else {
					pa[p] = p;
					ans++;
				}
				continue;
			}
			if (p == n) {
				if (p - 1 >= 1 && a[p - 1] > x) {
					pa[pa[p - 1]] = p;
					pa[p] = pa[p - 1];
				} else {
					pa[p] = p;
					ans++;
				}
				continue;
			}
			bool left = 0, right = 0;
			if (a[p - 1] > x) left = 1;
			if (a[p + 1] > x) right = 1;
			if (left && right) {
				ans--;
				pa[pa[p - 1]] = pa[pa[p + 1]];
				pa[pa[p + 1]] = pa[pa[p - 1]];
				continue;
			}
			if (left) {
				pa[pa[p - 1]] = p;
				pa[p] = pa[p - 1];
				continue;
			}
			if (right) {
				pa[pa[p + 1]] = p;
				pa[p] = pa[p + 1];
				continue;
			}
			pa[p] = p;
			ans++;
		}
	}
	return 0;
}
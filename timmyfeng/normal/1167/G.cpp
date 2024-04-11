#include <bits/stdc++.h> 
using namespace std;

const int MXN = 2e5;
const int MXD = 7500;

int a[MXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int m, cur = -MXD, l = 0, r = 0;
	bitset<MXD> left, right;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;

		left <<= x - cur;
		while (l < n && a[l] < x) {
			if (x - a[l] > MXD) {
				++l;
				continue;
			}
			left[x - a[l] - 1] = 1;
			++l;
		}
		right >>= x - cur;
		while (r < n && a[r] < x + MXD) {
			if (a[r] < x) {
				++r;
				continue;
			}
			right[a[r] - x] = 1;
			++r;
		}
		cur = x;

		int s = min(left._Find_first(), right._Find_first());
		int d = min({(left & right)._Find_first(), ((left << 1) & right)._Find_first(), ((right << 1) & left)._Find_first()});
		double ans = atan2(1, s);
		if (d < MXD) {
			ans = max(ans, 2 * atan2(1, d));
		}

		cout << ans << '\n';
	}
}
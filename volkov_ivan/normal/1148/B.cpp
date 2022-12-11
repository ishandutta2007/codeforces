#include <iostream>
#define int long long

using namespace std;

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	int a[n], b[m];
	int res = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	if (k >= min(n, m)) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i <= k; i++) {
		int left = -1, right = m, mid;
		while (right - left > 1) {
			mid = (left + right) / 2;
			if (a[i] + ta <= b[mid]) right = mid;
			else left = mid;
		}
		int rest = k - i;
		if (right + rest >= m) {
			cout << -1 << endl;
			return 0;
		}
		res = max(res, b[right + rest] + tb);
	}
	cout << res << endl;
	return 0;
}
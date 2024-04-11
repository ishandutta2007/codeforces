#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int MAX_N = 1e5 + 7;
int a[MAX_N], b[MAX_N];

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(b, b + m);
	int maxi = a[n - 1];
	if (maxi > b[0]) {
		cout << -1 << endl;
		return 0;
	}
	int s = 0;
	int t = 0;
	for (int i = 0; i < n; i++) t += a[i];
	for (int i = m - 1; i >= 1; i--) {
		s += t;
		s += b[i] - maxi;
	}
	s += t;
	if (b[0] != maxi) s += b[0] - a[n - 2];
	cout << s << endl;
	return 0;
}
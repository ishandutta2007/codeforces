#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater <int>());
	int s = 0;
	for (int i = 0; i < n; i++) s += a[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		cout << s - a[t - 1] << "\n";
	}
	return 0;
}
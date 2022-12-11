#include <iostream>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = INF, res = -1;
	for (int t = 1; t <= 101; t++) {
		int now = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < t) now += t - 1 - a[i];
			if (a[i] > t) now += a[i] - t - 1;
		}
		if (now < ans) {
			ans = now;
			res = t;
		}
	}
	cout << res << ' ' << ans << endl;
	return 0;
}
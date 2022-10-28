#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	int hi = 0;
	int lo = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		lo += a;
		if (lo > d) {
			cout << -1 << '\n';
			return 0;
		}

		hi = min(d, hi + a);
		if (!a) {
			if (hi < 0) {
				++ans;
				hi = d;
			}
			lo = max(0, lo);
		}
	}
	cout << ans << '\n';
}
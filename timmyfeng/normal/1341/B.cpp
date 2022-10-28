#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		int cur = 0;
		for (int i = 1; i < k - 1; ++i) {
			cur += (a[i] > a[i - 1] && a[i] > a[i + 1]);
		}
		
		int best = cur, ans = 1;
		for (int i = 1; i + k - 1 < n; ++i) {
			cur -= (a[i] > a[i - 1] && a[i] > a[i + 1]);
			cur += (a[i + k - 2] > a[i + k - 3] && a[i + k - 2] > a[i + k - 1]);
			if (cur > best) {
				best = cur;
				ans = i + 1;
			}
		}
		cout << best + 1 << ' ' << ans << '\n';
	}
}
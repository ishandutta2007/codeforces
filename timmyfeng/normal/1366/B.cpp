#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;

		int left = x, right = x;
		for (int i = 0; i < m; ++i) {
			int l, r;
			cin >> l >> r;
			if (r < left || right < l) {
				continue;
			}
			left = min(left, l);
			right = max(right, r);
		}

		cout << (right - left + 1) << '\n';
	}
}
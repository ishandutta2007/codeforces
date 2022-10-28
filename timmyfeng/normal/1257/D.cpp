#include <bits/stdc++.h>
using namespace std;

int a[200000], ps[200001];

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int strong = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			strong = max(strong, a[i]);
		}
		int m;
		cin >> m;
		fill(ps + 1, ps + 1 + n, 0);
		while (m--) {
			int p, s;
			cin >> p >> s;
			ps[s] = max(ps[s], p);
		}
		for (int i = n - 1; i; --i) {
			ps[i] = max(ps[i], ps[i + 1]);
		}
		if (strong > ps[1]) {
			cout << -1 << '\n';
			continue;
		}

		int ans = 0, mx = 0, start = 0;
		for (int i = 0; i < n; ++i) {
			mx = max(mx, a[i]);
			if (mx > ps[i - start + 1]) {
				++ans;
				mx = a[i];
				start = i;
			}
		}
		++ans;
		cout << ans << '\n';
	}
}
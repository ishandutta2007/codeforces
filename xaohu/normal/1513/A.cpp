#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n, k, ans[105];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n < 2 * k + 1) {
			cout << "-1\n";
			continue;
		}
		FOR(i, n) ans[i] = 0;
		FOR(i, k) ans[2 * i + 1] = n - i;
		int x = 1;
		FOR(i, n) {
			if (!ans[i]) ans[i] = x++;
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
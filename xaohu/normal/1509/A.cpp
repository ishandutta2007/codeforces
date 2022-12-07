#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n, a[2005];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		FOR(i, n)
			cin >> a[i];
		sort(a, a + n, [&](int x, int y) {
			if (x % 2 != y % 2)
				return x % 2 < y % 2;
			return x < y;
		});
		FOR(i, n)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
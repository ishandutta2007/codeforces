#include <bits/stdc++.h>
#define FOR(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main() {
	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		FOR(i, n) {
			cin >> a;
			ans += (a != 2);
		}
		cout << ans << "\n";
	}
	return 0;
}
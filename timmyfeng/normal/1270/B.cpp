#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int pre;
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (i && abs(pre - a) > 1) {
				ans = i;
			}
			pre = a;
		}

		if (ans == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << ans << " " << ans + 1 << "\n";
		}
	}
}
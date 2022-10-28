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
		int ans = 0;
		for (int i = 1; i < n / 2; ++i) {
			ans += 1 << i;
		}
		for (int i = n / 2; i < n; ++i) {
			ans -= 1 << i;
		}
		ans += 1 << n;
		cout << ans << '\n';
	}
}
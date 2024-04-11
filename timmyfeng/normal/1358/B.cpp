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
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			++mp[a];
		}

		int ans = 1, hold = 0;
		for (auto [a, b] : mp) {
			if (a <= ans + b + hold - 1) {
				ans += b + hold;
				hold = 0;
			} else {
				hold += b;
			}
		}
		cout << ans << '\n';
	}
}
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
		vector<int> s(n);
		for (auto& i : s) {
			cin >> i;
		}
		sort(s.begin(), s.end());

		int ans = -1;
		for (int i = 1; i < (1 << 10); ++i) {
			vector<int> t(n);
			for (int j = 0; j < n; ++j) {
				t[j] = s[j] ^ i;
			}
			sort(t.begin(), t.end());
			if (t == s) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}
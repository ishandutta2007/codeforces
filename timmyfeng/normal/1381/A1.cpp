#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		cin >> n >> a >> b;

		vector<int> ans;
		for (int i = n - 1; i; --i) {
			if (a[i] != b[i]) {
				if (a[0] != a[i]) {
					ans.push_back(0);
					a[0] = '1' + '0' - a[0];
				}
				ans.push_back(i);
				for (int j = 0; j <= i; ++j) {
					a[j] = '1' + '0' - a[j];
				}
				reverse(a.begin(), a.begin() + i + 1);
			}
		}

		if (a[0] != b[0]) {
			ans.push_back(0);
		}

		cout << ans.size() << " ";
		for (auto & i : ans) {
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
}
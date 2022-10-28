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
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				a[j] = (i + j) % 2 ? max(a[j], -a[j]) : min(a[j], -a[j]);
			}
			bool ok = true;
			for (int j = 1; j < n; ++j) {
				ok &= ((i + j) % 2 ? a[j] >= a[j - 1] : a[j] <= a[j - 1]);
			}
			if (ok)
				break;
		}
		
		for (auto& i : a) {
			cout << i << " ";
		}
		cout << "\n";
	}
}
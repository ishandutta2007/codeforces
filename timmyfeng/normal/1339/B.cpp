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
		sort(a.begin(), a.end());
		for (int i = n / 2 - 1, j = n / 2; j < n; ++j, --i) {
			cout << a[j] << ' ';
			if (i >= 0) {
				cout << a[i] << ' ';
			}
		}
		cout << '\n';
	}
}
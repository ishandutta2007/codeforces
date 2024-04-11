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
		bool ok = true;
		sort(a.begin(), a.end());
		for (int i = 1; i < n; ++i) {
			if (a[i] - a[i - 1] == 1) {
				ok = false;
			}
		}
		cout << 2 - ok << '\n';
	}
}
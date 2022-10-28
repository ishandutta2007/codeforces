#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		set<int> seen;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			seen.insert(a);
		}
		if (seen.size() > k) {
			cout << -1 << '\n';
			continue;
		}
		cout << k * n << '\n';
		for (int i = 0; i < n; ++i) {
			for (auto j : seen) {
				cout << j << ' ';
			}
			for (int j = seen.size(); j < k; ++j) {
				cout << 1 << ' ';
			}
		}
		cout << '\n';
	}
}
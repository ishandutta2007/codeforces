#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a == n && i >= k1) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}
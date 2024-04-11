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
		vector<int> pos(n);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			--a;
			pos[a] = i;
		}

		bool ok = false;
		for (int i = n - 1; i >= 0; --i) {
			if (pos[i] == n - 1) {
				ok = true;
				break;
			} else if (pos[i] == 0) {
				ok = false;
				break;
			}
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}
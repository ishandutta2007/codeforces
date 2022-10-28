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

		int l = 0;
		int r = n - 1;
		int m = -1;
		for (int i = n - 1; i; --i) {
			if (pos[i] == l) {
				++l;
			} else if (pos[i] == r) {
				--r;
			} else {
				m = pos[i];
				break;
			}
		}

		if (m == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << l + 1 << " " << m + 1 << " " << r + 1 << "\n";
		}
	}
}
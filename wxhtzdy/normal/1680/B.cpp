#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'E') {
				continue;
			}

			bool ok = true;
			for (int k = 0; k < n; k++) {
				for (int p = 0; p < m; p++) {
					if (s[k][p] == 'R' && (k < i || p < j)) {
						ok = false;
					}
				}
			}
			if (ok) {
				std::cout << "YES\n";
				return;
			}
		}
	}
	std::cout << "NO\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) solve();

	return 0;
}
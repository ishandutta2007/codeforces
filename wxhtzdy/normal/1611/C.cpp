#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	if (a[0] != n && a[n - 1] != n) {
		std::cout << "-1\n";
	} else {
		for (int i = n - 1; i >= 0; i--) {
			std::cout << a[i] << " ";
		}
		
		std::cout << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;	
}
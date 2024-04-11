#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n / 2; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << i << " " << j << "\n";
			cout << n + 1 - i << " " << m + 1 - j << "\n";
		}
	}

	if (n % 2) {
		for (int j = 1; j <= (m + 1) / 2; ++j) {
			cout << (n + 1) / 2 << " " << j << "\n";
			if (m + 1 - j != j) {
				cout << (n + 1) / 2 << " " << m + 1 - j << "\n";
			}
		}
	}
}
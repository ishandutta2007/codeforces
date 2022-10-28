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
		if (n % 4) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for (int i = 2; i <= n; i += 2) {
			cout << i << ' ';
		}
		for (int i = 1; i < n - 1; i += 2) {
			cout << i << ' ';
		}
		cout << n + n / 2 - 1 << '\n';
	}
}
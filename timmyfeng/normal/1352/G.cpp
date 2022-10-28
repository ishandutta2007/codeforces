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
		if (n <= 3) {
			cout << -1 << '\n';
		} else {
			for (int i = n - n % 2; i > 4; i -= 2) {
				cout << i << ' ';
			}
			cout << 2 << ' ' << 4 << ' ';
			for (int i = 1; i <= n; i += 2) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
}
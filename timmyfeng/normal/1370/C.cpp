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
		if (n == 1) {
			cout << "FastestFinger\n";
		} else if (n % 2) {
			cout << "Ashishgup\n";
		} else {
			n /= 2;
			bool ok = n == 1;
			for (int i = 2; i * i <= n; ++i) {
				if (n % i == 0 && (n / i % 2 || i % 2)) {
					ok = true;
					break;
				}
			}
			cout << (ok ? "Ashishgup" : "FastestFinger") << "\n";
		}
	}
}
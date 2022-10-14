#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		if (n >= k && abs(n - k - 1) % 2 == 1) {
			cout << "YES" << endl;
			cout << n - k + 1 << " ";
			for (int i = 0; i < k - 1; i++) {
				cout << 1 << " ";
			}
			cout << endl;
		} else {
			if(n >= k * 2 && (n - (k - 1) * 2) % 2 == 0) {
				cout << "YES" << endl;
				cout << n - (k - 1) * 2 << " ";
				for (int i = 0; i < k - 1; i++) {
					cout << 2 << " ";
				}
				cout << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}
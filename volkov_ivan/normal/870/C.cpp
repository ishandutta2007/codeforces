#include <iostream>
#include <vector>

using namespace std;

int main() {
	int q, n, k;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		if (n % 4 == 0) {
			cout << n / 4 << endl;
			continue;
		}
		if (n % 4 == 2) {
			if (n == 2) {
				cout << -1 << endl;
			} else {
				cout << (n - 6) / 4 + 1 << endl;
			}
			continue;
		}
		if (n % 4 == 1) {
			if (n < 9) {
				cout << -1 << endl;
			} else {
				cout << (n - 9) / 4 + 1 << endl;
			}
			continue;
		}
		if (n % 4 == 3) {
			if (n < 15) {
				cout << -1 << endl;
			} else {
				cout << (n - 15) / 4 + 2 << endl;
			}
		}
	}
	return 0;
}
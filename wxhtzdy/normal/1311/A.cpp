#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			cout << ((a - b) % 2 == 1 ? 2 : 1) << endl;
		} else {
			if (a == b) {
				cout << 0 << endl;
			}
			else {
				cout << ((b - a) % 2 == 0 ? 2 : 1) << endl;
			}
		}
	}
}
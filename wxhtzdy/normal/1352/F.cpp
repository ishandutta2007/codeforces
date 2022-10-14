#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > 0) {
			if (a > 0 && c > 0) {
				b--;
				for (int i = 0; i < b; i++) {
					cout << (b % 2 == i % 2 ? 0 : 1);
				}
			} else {
				if (a == 0 && c == 0) {
					cout << (b % 2 ? 0 : 1);
					for (int i = 0; i < b; i++) {
						cout << (b % 2 == i % 2 ? 0 : 1);
					}	
				} else {
					if (a == 0 && c > 0) {
						for (int i = 0; i < b; i++) {
							cout << (b % 2 != i % 2 ? 0 : 1);
						}
					} else {
						for (int i = 0; i < b; i++) {
							cout << (b % 2 == i % 2 ? 0 : 1);
						}
					}
				}
			}
		}
		if (a > 0) {
			cout << "00";
			for (int i = 0; i < a - 1; i++) {
				cout << 0;
			}
		}
		
		if (c > 0) {
			cout << "11";
			c--;
			for (int i = 0; i < c; i++) {
				cout << 1;
			}
		}
		cout << endl;
	}
	return 0;
}
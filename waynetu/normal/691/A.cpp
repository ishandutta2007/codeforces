#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	int b = 0;
	if (n == 1) {
		cin >> x;
		if (x == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		return 0;
	} else {
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x == 0) {
				b++;
			}
			if (b == 2) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (b == 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;	
	}
	
	return 0;
}
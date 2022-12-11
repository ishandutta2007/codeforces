#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	if (a <= 2 && b <= 2) {
		cout << 0 << endl;
		return 0;
	}
	if (a == 1 && b == 3) {
		cout << 0 << endl;
		return 0;
	}
	if (a == 2 && b == 3) {
		cout << 4 << endl;
		return 0;
	}
	if (a == 1) {
		if (b % 6 == 4 || b % 6 == 2) {
			cout << b - 2 << endl;
			return 0;
		}
		if (b % 6 == 5 || b % 6 == 1) {
			cout << b - 1 << endl;
			return 0;
		}
		if (b % 6 == 0) {
			cout << b << endl;
			return 0;
		}
		if (b % 6 == 3) {
			cout << b - 3 << endl;
			return 0;
		}
	}
	if (a == 2 && b == 7) {
		cout << a * b - 2 << endl;
		return 0;
	}
	cout << a * b - (a * b % 2) << endl;
	return 0;
}
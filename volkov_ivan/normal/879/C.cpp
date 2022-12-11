#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int x, zero = 0, one = 1023, c1 = 0, c2 = 0, c3 = 0;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c >> x;
		if (c == '^') {
			one ^= x;
			zero ^= x;
		}
		if (c == '|') {
			one |= x;
			zero |= x;
		}
		if (c == '&') {
			one &= x;
			zero &= x;
		}
	}
	//cout << zero << ' ' << one << endl;
	for (int i = 0; i < 10; i++) {
		if ((zero & (1 << i)) == 0) {
			if ((one & (1 << i)) == 0) {
				continue;
			} else {
				c2 |= (1 << i);
			}
		} else {
			if ((one & (1 << i)) == 0) {
				c1 |= (1 << i);
				c2 |= (1 << i);
			} else {
				c3 |= (1 << i);
			}
		}
	}
	cout << 3 << endl;
	cout << "^ " << c1 << endl;
	cout << "& " << c2 << endl;
	cout << "| " << c3 << endl;
	return 0;
}
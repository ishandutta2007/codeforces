#include <iostream>

using namespace std;

int main() {
	long long l, r, x, y, k, a, b;
	cin >> l >> r >> x >> y >> k;
	b = x;
	while (b <= y) {
		a = k * b;
		if (l <= a && a <= r) {
			cout << "YES" << endl;
			return 0;
		}
		b++;
	}
	cout << "NO" << endl;
	return 0;
}
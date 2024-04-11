#include <iostream>

using namespace std;

int main() {
	int n, x, a;
	cin >> n >> x;
	int now = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		now += a;
	}
	if (now == x) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
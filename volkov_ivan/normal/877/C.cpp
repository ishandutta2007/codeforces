#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n + n / 2 << endl;
	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 1; i <= n; i += 2) {
		cout << i << ' ';
	}
	for (int i = 2; i <= n; i += 2) {
		cout << i << ' ';
	}
	return 0;
}
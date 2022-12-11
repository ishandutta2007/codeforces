#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != d) {
		cout << "0" << endl;
		return 0;
	}
	if (c != 0 && a == 0) {
		cout << "0" << endl;
		return 0;
	}
	cout << "1" << endl;
	return 0;
}
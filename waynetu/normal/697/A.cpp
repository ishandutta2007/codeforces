#include <iostream>
using namespace std;

int main() {
	long long int t, s, x;
	cin >> t >> s >> x;
	long long int d = x - t;
	if (d < s) {
		if (d == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		if (d % s == 0 || d % s == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
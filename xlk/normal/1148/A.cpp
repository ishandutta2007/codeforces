#include <bits/stdc++.h>
using namespace std;
int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	if (B > A + 1) {
		B = A + 1;
	}
	if (A > B + 1) {
		A = B + 1;
	}
	cout << (A + B + 2 * C) << endl;
	return 0;
}
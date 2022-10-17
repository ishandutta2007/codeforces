#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int main() {
	cin >> n >> a >> b >> c;
	if (n == 1) {
		cout << 0 << endl;
	} else {
		cout << min(a, b) + (n - 2) * min(min(a, b), c) << endl;
	}
	return 0;
}
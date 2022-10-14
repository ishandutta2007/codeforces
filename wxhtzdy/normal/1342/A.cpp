#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long x, y;
		cin >> x >> y;
		long long a, b;
		cin >> a >> b;
		if (x < 0 && y < 0) {
			x *= -1;
			y *= -1; 
		}
		if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
			cout << (abs(x) + abs(y)) * a << endl;
			continue;
		}
		if (a * 2 <= b) {
			cout << (abs(x) + abs(y)) * a << endl;
		} else {
			cout << min(abs(x), abs(y)) * b + (max(abs(x), abs(y)) - min(abs(x), abs(y))) * a << endl;
		}
	}
	return 0;
}
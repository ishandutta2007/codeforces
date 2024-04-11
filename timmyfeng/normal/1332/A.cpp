#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		int x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x == x1 && x == x2 && (a || b)) {
			cout << "No" << '\n';
			continue;
		}
		if (y == y1 && y == y2 && (c || d)) {
			cout << "No" << '\n';
			continue;
		}
		x += b - a;
		y += d - c;
		cout << (x >= x1 && x <= x2 && y >= y1 && y <= y2 ? "Yes" : "No") << '\n';
	}
}